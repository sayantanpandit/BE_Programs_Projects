/*
To delete all the occurances of an element from a list.
*/

%base_case
delAll(_, [], []).

%inductive_case
delAll(A, [A|L], M):- !, delAll(A, L, M).

delAll(A, [B|L], [B|M]):- delAll(A, L, M).

/*
Output
?- delAll(5, [1,2,3,5,4,5], L).
L = [1, 2, 3, 4] 
*/
