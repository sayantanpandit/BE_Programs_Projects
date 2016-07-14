flatten([], []) :- !.
flatten([L|Ls], FlatL) :- !,
			  flatten(L, NewL),
			  flatten(Ls, NewLs),
			  append(NewL, NewLs, FlatL).
			  flatten(L, [L]).
			  
/*
?- flatten([1,[2,3],[4,5],6,7,8],L).
L = [1, 2, 3, 4, 5, 6, 7, 8].

?- flatten([1,[]],L).
L = [1].

?- flatten([[],1],L).
L = [1].
*/
