
%start_case
multiply(0,N,0):-    natural_number(N).
multiply(s(M),N,Z):- multiply(M,N,W), 
		     addition(W,N,Z).

natural_number(0).
natural_number(s(N)):- natural_number(N).

addition(0,N,N):-natural_number(N).
addition(s(M),N,s(Z)):-addition(M,N,Z).


/* OUTPUT 
?- multiply(s(s(0)), s(s(s(0))), L).
L = s(s(s(s(s(s(0)))))).

*/
