natural_number(0).
natural_number(s(N)):-natural_number(0).
mycount(0,1).
mycount(s(N),Z):-mycount(N,Z1),Z is Z1+1.
subtract(N,0,N):-natural_number(N),!.
subtract(M,s(N),Z):-subtract(M,N,s(Z)).
division(M,N,0):-mycount(M,Val1),mycount(N,Val2),Val1<Val2,!.
division(M,N,s(Z)):-subtract(M,N,W),division(W,N,Z).
/*
Testing
?- division(s(0),s(s(0)),Z).
Z = 0.

?- division(s(s(0)),s(s(0)),Z).
Z = s(0).

?- division(s(s(s(0))),s(s(0)),Z).
Z = s(0).

?- division(s(s(s(s(0)))),s(s(0)),Z).
Z = s(s(0)).

?- division(s(s(s(s(s(0))))),s(s(0)),Z).
Z = s(s(0)).

?- division(s(s(s(s(s(s(0)))))),s(s(0)),Z).
Z = s(s(s(0))).
*/
