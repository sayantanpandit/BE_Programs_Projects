
squareroot(0,0):-!.
squareroot(M,R):- multiply(R,R,Val1),
		  multiply(s(R),s(R),Val2),
		  lessthanequal(Val1,M),
		  greaterthan(Val2,M),
		  !.

natural_number(0).
natural_number(s(N)):-natural_number(N).

count(0,0).
count(s(N),R):- count(N,R1),
		R is R1+1.
lessthanequal(M,N):- count(M,Val1),
		     count(N,Val2),
		     Val1=<Val2.

greaterthan(M,N):-count(M,Val1),
		  count(N,Val2),
		  Val1>Val2.

addition(0,N,N):-natural_number(N).
addition(s(M),N,s(Z)):-addition(M,N,Z).

multiply(0,N,0) :- natural_number(N).
multiply(s(M),N,Z) :- multiply(M,N,W), 
		      addition(W,N,Z).
		      
/*OUTPUT
?- squareroot(s(s(s(s(0)))), L).
L = s(s(0)).
*/		      
