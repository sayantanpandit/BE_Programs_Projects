/*
To delete the first occurance of an element from a list
*/

%base_case
efface(_, [], []).

%inductive_case
efface(A, [A|L], L):- !.

efface(A, [B|L], [B|M]):- efface(A, L, M).

/*
Output :
?- efface(5, [1,2,5, 6,5], L).
L = [1, 2, 6, 5].

?- efface(5, [1,2,5, 6,5, 6, 5], L).
L = [1, 2, 6, 5, 6, 5].
*/
