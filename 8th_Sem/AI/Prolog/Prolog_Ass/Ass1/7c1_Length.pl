/*
To determine the length of a list without using accumulator
*/

%base_case
lengthWOAcc([], 0).

%inductive_case
lengthWOAcc([H|T], N):- lengthWOAcc(T, N1), 
		      	N is N1+1.
		      	
/*
OUTPUT
?- lengthWOAcc([a,b,c, ef, d], L).
L = 5.

?- lengthWOAcc([a,b,c, e, d], L).
L = 5.
*/		      	
