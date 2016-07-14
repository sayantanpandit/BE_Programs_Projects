append([],L,L):-!.
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).
next_to(X,Y,L):-append(_,[X|[Y|_]],L).
/* 
?- next_to(1,2,[1,2,3]).
true.

?- next_to(1,2,[2,3]).
false.

.*/

