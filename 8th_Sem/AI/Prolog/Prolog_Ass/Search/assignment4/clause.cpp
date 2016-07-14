#include"clause.h"

clause::clause(){
	
	for(int i=1; i <= N_LITERALS; i++)
		cl[i]=0;
	
	parent[0]=-1;
	parent[1]=-1; //No parents
}

void clause::insertLiteral(const int &l){
	if(l>0)	cl[l] = 1;
	else cl[-l] = -1;
}

void clause::print(std::string symbolTable[]){
	
	printf("{");
	for(int i=1; i<=N_LITERALS; i++){
		if(cl[i]==1)
			printf("%s ", symbolTable[i].c_str());
		if(cl[i]==-1)
			printf("~%s ", symbolTable[i].c_str());
	}
	printf("}");
}

clause *clause::resolve(clause *rhs,int parent0, int parent1){

	clause *result = new clause();

	for(int i=1; i<=N_LITERALS; i++){
		
		if(rhs->cl[i] == this->cl[i])
			result->cl[i] = rhs->cl[i];
		else result->cl[i] = this->cl[i] + rhs->cl[i];
	}
	
	result->parent[0] = parent0;
	result->parent[1] = parent1;	
	
	
	if(!result->isEmpty())	return result;
	
	return result;
}

bool clause::matches(const clause *rhs){

	for(int i=1; i<=N_LITERALS; i++)
		if(this->cl[i]!=rhs->cl[i])	return false;
	return true;
}

bool clause::isEmpty(){
	for(int i=1; i<=N_LITERALS; i++)
		if(cl[i]!=0)	return false;
	return true;
}










