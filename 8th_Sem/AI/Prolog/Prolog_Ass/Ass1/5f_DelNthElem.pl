/*
To delete nth Element in L, leaving the rest in L1.
*/

%base_case
delNth(_, [], []):- !.

%inductive_case
delNth(1, [H|T], T):- !.
delNth(N, [H|T], [H|T1]):- N1 is N-1,
		           delNth(N1,T,T1).
		       		       
/* OUTPUT 
?- delNth(3, [1,2,3,4,5], L).
L = [1, 2, 4, 5].

?- delNth(1, [5], L).
L = [].
*/		       
