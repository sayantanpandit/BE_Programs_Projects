natural_number(0).
natural_number(s(N)):-natural_number(N).
count(0,0).
count(s(N),R):-count(N,R1),R is R1+1.
lessthan(M,N):-count(M,Val1),count(N,Val2),Val1<Val2.
subtract(N,0,N):-natural_number(N),!.
subtract(M,s(N),Z):-subtract(M,N,s(Z)).
remainder(M,N,M):-lessthan(M,N),!.
remainder(M,N,R):-subtract(M,N,W),remainder(W,N,R).
/*
?- remainder(s(s(s(0))),s(s(0)),L).
L = s(0).

?- remainder(s(s(s(s(0)))),s(s(0)),L).
L = 0.

?- remainder(s(s(s(s(0)))),s(s(s(0))),L).
L = s(0).
*/

