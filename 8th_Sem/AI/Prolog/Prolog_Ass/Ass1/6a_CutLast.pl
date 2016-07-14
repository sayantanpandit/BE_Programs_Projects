/*
WAPP to cutlast(L, L1) that defines L1 to be obtained 
from L with last element removed.
*/

%base_case
cutlast([],[]).
cutlast([X],[]).

%inductive_case
cutlast([H|T],[H|T1]):- cutlast(T,T1).

/* OUTPUT
?- cutlast([1,6,3,5,6], L).
L = [1, 6, 3, 5] .
*/
