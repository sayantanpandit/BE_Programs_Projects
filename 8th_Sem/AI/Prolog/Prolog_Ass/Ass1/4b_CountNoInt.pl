/*
WAPP to count number of integers > 100 in a list of given integers.
*/

%base_case
count([],0).

%inductive_case
count([H|T],C):- H>100,
		 !,
		 count(T,C1),
		 C is C1+1.
count([H|T],C):- count(T,C).

/* OUTPUT
?- count([102, 99, 106],L).
L = 2.
*/
