sum(0,N,N):-!.
sum(M,N,R):- M>0,
	     M1 is M-1,
	     sum(M1,N,R1),
	     R is R1+1,
	     !.
	     
sum(M,N,R):- M<0,
	     M1 is M+1,
	     sum(M1,N,R1),
	     R is R1-1.
	     
subtract(N,0,N):- !.
subtract(M,N,R):- N>0,
		  N1 is N-1,
		  subtract(M,N1,R1),
		  R is R1-1,
		  !.
		  
subtract(M,N,R):- N<0,
		  N1 is N+1,
		  subtract(M,N1,R1),
		  R is R1+1.
division(0,N,0):- !.
division(M,N,0):- M>0,
		  N>0,
		  M<N,
		  !.
division(M,N,0):- M<0,
		  N<0,
		  M>N,!.

division(M,N,R):- M>0,
		  N>0,
		  subtract(M,N,M1),
		  division(M1,N,R1), 
		  R is R1+1,!.

division(M,N,R):- M>0,
		  N<0,
		  sum(M,N,M1),
		  division(M1,N,R1), 
		  R is R1-1,!.
		  
division(M,N,R):- M<0,
		  N>0,
		  sum(M,N,M1),
		  division(M1,N,R1), 
		  R is R1-1,
		  !.
		  
division(M,N,R):- M<0,
		  N<0,
		  subtract(M,N,M1),
		  division(M1,N,R1), 
		  R is R1+1.
