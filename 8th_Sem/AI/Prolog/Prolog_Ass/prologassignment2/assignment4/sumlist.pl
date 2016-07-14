sumlist([],0):-!.
sumlist([X],X):-!.
sumlist([H|T],Sum):-sumlist(T,SumTail), Sum is SumTail+H.
/*
?- sumlist([1],L).
L = 1.

?- sumlist([],L).
L = 0.

?- sumlist([1,2,3],L).
L = 6.
*/
