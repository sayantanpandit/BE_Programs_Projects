interleave([],[],[]):-!.
interleave(L,[],L):-!.
interleave([],L,L):-!.
interleave([H1|L1],[H2|L2],[H1|[H2|L]]):-interleave(L1,L2,L).
/*
Check:
?- interleave([],[],L).
L = [].

?- interleave([1],[2],L).
L = [1, 2].

?- interleave([1,3],[2],L).
L = [1, 2, 3].

?- interleave([1,3],[2,4],L).
L = [1, 2, 3, 4].

?- interleave([1,3,5],[2,4],L).
L = [1, 2, 3, 4, 5].
*/
