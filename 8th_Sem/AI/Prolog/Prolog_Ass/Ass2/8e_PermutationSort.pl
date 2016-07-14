/* PERMUTATION SORT */

permutationsort([],[]):- !.

permutationsort(L,L1):-	permutation(L,L1),
			ordered(L1).

permutation([],[]):- !.

permutation([H|T], L):- permutation(T,Z),
			selectElem(H,L,Z).
	
ordered([]):-!.
ordered([X]):-!.
ordered([X|[Y|Rest]]):- X=<Y,
	                ordered([Y|Rest]).

selectElem(H,[H|T],T).
selectElem(X, [H|T], [H|T1]):- selectElem(X,T,T1).


/*
?- permutationsort([32,1,15,6], L).
L = [1, 6, 15, 32] .
*/
