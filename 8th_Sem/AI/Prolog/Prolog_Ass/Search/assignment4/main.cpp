#include"clause.h"
using namespace std;

void findLiterals(char[],vector<string>&);
void printPath(const int&,vector<clause*>&,string[]);

int main(){

	vector<clause*> clauseList;
	clause *newClause;
	char line[LINESIZE];
	map<string,int> symbolMap;
	
	string symbolTable[N_LITERALS];
	int last_literal_index = 0;
	
	vector<string> literals;
	int n;
	int j;
	char ch;
	bool isNegated;
	
	// Taking input /////////////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("Number of clauses: "); scanf("%d",&n);
	getchar();
	printf("Enter the clauses====\n");
	
	for(int i=1; i <= n; i++){
		
		//Input a line as clause	
		j=0;
		do{
			if( (ch=getchar())!='\n')
				line[j++] = ch;
		}while(ch!='\n');
		line[j] = '\0';
		
		// Seperating literals
		findLiterals(line,literals);
		newClause = new clause();
		
		
		// Decoding the clause
		for(int item=0; item<literals.size(); item++){
	
			// Checking whether it's a negation of an atom
			if(literals[item][0]=='~'){
				isNegated = true;
				literals[item] = string(literals[item].c_str()+1);
			}
			else isNegated = false;
						
			if(symbolMap[literals[item]] == 0){
				symbolMap[literals[item]] = (++last_literal_index);
				symbolTable[last_literal_index]=literals[item];
			}
			if(isNegated)	newClause->insertLiteral(-symbolMap[literals[item]]);
			else newClause->insertLiteral(symbolMap[literals[item]]);
		}
		
		// Inserting the clause
		clauseList.push_back(newClause);	
	}
	
	
	// Printing given clauses
	for(int i=0; i<clauseList.size(); i++){
			printf("\n%d) ",i+1);	
			clauseList[i]->print(symbolTable);
	}
	printf("\n\n");
	
	// Resolution algorithm /////////////////////////////////////////////////////////////////////////////////////////

	int first;
	int second;
	int iterator;
	clause *resolvant;
	vector<clause*> newClauses;
	int new_from_index = 0;

	while(true){
	
		newClauses.clear();
	
		for(first=0; first<clauseList.size(); first++){
			for(second = MAXM(new_from_index,first+1) ; second<clauseList.size(); second++){
			
			
				resolvant = clauseList[first]->resolve(clauseList[second],first,second);
				
				//printf("Resolvant:");	resolvant->print(symbolTable);
				
				if(resolvant->isEmpty()){
					// Conclusion is reached. 
					// Printing the path 
					clauseList.push_back(resolvant);
		
					printPath(clauseList.size()-1, clauseList, symbolTable);
					printf("\n");
					break;
				}
				
				//Checking whether it's an old cluase
				for(iterator=0; iterator<clauseList.size(); iterator++)
					if(clauseList[iterator]->matches(resolvant))	break;
				if(iterator<clauseList.size())	continue;
				
				// Keeping as a new clause
				newClauses.push_back(resolvant);
			}
			if(second<clauseList.size()) break;
		}
		
		if(resolvant->isEmpty()) break;
		
		if(newClauses.empty()){
			printf("Conclusion cannot be reached.\n");
			return 0;
		}
		
		// Adding new clauses to the former list
		new_from_index = clauseList.size();
		
		for(iterator=0; iterator<newClauses.size(); iterator++)
			clauseList.push_back(newClauses[iterator]);
		
	}
	

	return 0;
}

void printPath(const int &index, vector<clause*> &clauseList, string symbolTable[]){

	if(clauseList[index]->parent[0] < 0){	//No parent
		return;
	}
	
	printPath(clauseList[index]->parent[0], clauseList, symbolTable);
	printPath(clauseList[index]->parent[1], clauseList, symbolTable);
	
	printf("%d) ",index+1);
	clauseList[index]->print(symbolTable);
	printf(" from %d and %d\n", clauseList[index]->parent[0]+1, clauseList[index]->parent[1]+1);
	
}

void findLiterals(char line[], vector<string> &literals){

	int i;
	int j;
	int k;
	char token[LINESIZE];

	i=0;
	literals.clear();
	do{

		// Avoing white spaces
		for(j=i ; line[j]==' '; j++);

		k=0;
		for( ; line[j]!=',' && line[j]!=' ' && line[j]!='\0' ; j++)
			token[k++]=line[j];
		token[k]='\0';
		
		literals.push_back(string(token));
		
		// Avoing white spaces
		for( ; line[j]==' '; j++);
		if(line[j]=='\0')	return;

		i=j+1;

	}while(true);
}













