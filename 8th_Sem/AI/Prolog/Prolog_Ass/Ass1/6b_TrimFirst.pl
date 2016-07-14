/*
trim(N, L, L1) that defines L1 to be obtained from L 
with first N elements removed.
*/

%base_case
trim(_, [], []).
trim(1, [X|T], T).

%inductive_case
trim(N, [H|T], T1):- N1 is N-1,
		     trim(N1,T,T1).
		     
/*
OUTPUT
?- trim(2, [1,6,3,5,6], L).
L = [3, 5, 6] .

?- trim(1, [], L).
L = [] .
*/		     
