append([],L,L).
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).
myreverse([],[]).
myreverse([H|T],L):-myreverse(T,Z),append(Z,[H],L).
