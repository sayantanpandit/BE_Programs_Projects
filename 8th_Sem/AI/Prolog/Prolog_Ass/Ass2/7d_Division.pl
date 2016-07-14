
%start_case
division(M,N,0):- count(M,Val1),
		  count(N,Val2),
		  Val1<Val2,
		  !.
		  
division(M,N,s(Z)):- subtract(M,N,W),
	             division(W,N,Z).

natural_number(0).
natural_number(s(N)):-natural_number(0).

count(0,1).
count(s(N),Z):- count(N,Z1),
		Z is Z1+1.

subtract(N,0,N):-natural_number(N),!.
subtract(M,s(N),Z):-subtract(M,N,s(Z)).

/* OUTPUT 
?- division(s(s(s(s(0)))),s(s(0)), L).
L = s(s(0)).
*/
