/*
Recursive Programs in Prolog to Subtract Two Integers.
*/

%base_case
subtract(N,0,N):-!.

%inductive_case
subtract(M,N,R):- N>0,
		  !,
		  N1 is N-1,
		  subtract(M,N1,R1),
		  R is R1-1.
		  
subtract(M,N,R):- N<0,
		  !,
		  N1 is N+1,
		  subtract(M,N1,R1),
		  R is R1+1.
