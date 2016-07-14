meanlist([],0,0):-!.
meanlist([X],X,1):-!.
meanlist([H|T],Sum,L):-meanlist([T],SumTail,LTail),Sum is SumTail+H, L is LTail+1.
mean([],0):-!.
mean([X],X):-!.
mean(List,Result):-meanlist(List,Sum,L), Result is Sum/L.
/*
Check:
?- mean([],X).
X = 0.

?- mean([1],X).
X = 1.

?- mean([2,3],X).
X = 2.5.
*/
