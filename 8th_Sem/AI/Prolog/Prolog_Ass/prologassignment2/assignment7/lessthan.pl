natural_number(0).
natural_number(s(N)):-natural_number(N).
count(0,0).
count(s(N),R):-count(N,R1),R is R1+1.
lessthan(M,N):-count(M,Val1),count(N,Val2),Val1<Val2.
/*
?- lessthan(s(s(0)),s(0)).
false.

?- lessthan(s(0),s(s(0))).
true.

?- lessthan(s(0),s(0)).
false.
*/
