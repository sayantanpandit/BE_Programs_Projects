/*
To remove duplicate elements from a list.
L: List with duplicate
M: List without duplicate
*/

%base_case
our_member(X, [X|_]):- !.
%inductive_case
our_member(X, [_|Y]):- our_member(X, Y).

removeDup(L, M):- removeAcc(L, [], M).

%base_case
removeAcc([], A, A).

%inductive_case
removeAcc([H|T], A, M):- our_member(H, A), 
			 !, 
			 removeAcc(T, A, M).

removeAcc([H|T], A, M):- removeAcc(T, [H|A], M).

/*
OUTPUT:
?- removeDup([1,2,3,5,3,4,6], L).
L = [6, 4, 5, 3, 2, 1].

?- removeDup([1,2,3,3,3,4,6], L).
L = [6, 4, 3, 2, 1].
*/
