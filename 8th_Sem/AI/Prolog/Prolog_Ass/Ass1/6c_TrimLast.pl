/*
trimlast(N, L, L1) defines that L1 to be obtained from L with last N elements removed.
*/

%base_case
trimlast(_,[],[]).

%inductive_case
trimlast(N,L,L1):- reverse(L,R),
		   trim(N,R,L1).
		   
/*OUTPUT
?- trimlast(2, [1,2,3,4,5], L).
L = [3, 2, 1] .
*/		   
