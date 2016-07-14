permutationsort([],[]):-!.

permutationsort(L,L1):-
	my_permutation(L,L1),
	ordered(L1).

my_permutation([],[]):-!.

my_permutation([H|T], L):-
	my_permutation(T,Z),
	my_select(H,L,Z).
	
ordered([]):-!.
ordered([X]):-!.
ordered([X|[Y|Rest]]):-
	X=<Y,
	ordered([Y|Rest]).

my_select(H,[H|T],T).
my_select(X, [H|T], [H|T1]):-
	my_select(X,T,T1).


/*Check:-
?- permutationsort([1,4,3,2],L).
L = [1, 2, 3, 4] ;
false.

?- permutationsort([1,4,3,2],L).
L = [1, 2, 3, 4] ;
false.

?- permutationsort([1,2,3,4],L).
L = [1, 2, 3, 4] ;
false.

?- permutationsort([1,2,5,3,4],L).
L = [1, 2, 3, 4, 5] ;
false.
*/

