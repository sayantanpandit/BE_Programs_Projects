bubblesort(L,L):-
	ordered(L),!.

bubblesort(L1,L2):-
		append(X,[A,B|Y],L1),
		A>B,!,
		append(X,[B,A|Y],T),
		bubblesort(T,L2).

append([],L,L).
append([X|L1],L2,[X|L3]):-
	append(L1,L2,L3).

ordered([]):-!.
ordered([X]):-!.
ordered([X,Y|Rest]):-
	X=<Y,
	ordered([Y|Rest]).
/*
?- bubblesort([2,1,4,3],L).
L = [1, 2, 3, 4].

?- bubblesort([2,1,4,5,3],L).
L = [1, 2, 3, 4, 5].
*/
