myappend([],L,L).
myappend([X|L1],L2,[X|L]):-myappend(L1,L2,L).
mymember(X,L):-myappend(L1,[X|L2],L).

