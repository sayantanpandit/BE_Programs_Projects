#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#define N_LITERALS 20
#define LINESIZE 100
#define MAXM(X,Y) (X)>(Y)?(X):(Y)

class clause{
	
	public: //testing
		char cl[N_LITERALS+1];	// 1 indexed
	
	public:
		
		int parent[2];
	
		clause();
		void insertLiteral(const int&);	
		void print(std::string[]);
		
		clause *resolve(clause*,int,int); 
		bool matches(const clause*);
		bool isEmpty();

};
