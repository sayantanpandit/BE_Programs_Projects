transpose([],[],[]).
transpose([H1|L1],[H2|L2],[(H1,H2)|L]):-transpose(L1,L2,L).
/*
?- transpose([1],[2],L).
L = [ (1, 2)].

?- transpose([1,3],[2,4],L).
L = [ (1, 2), (3, 4)].
*/
