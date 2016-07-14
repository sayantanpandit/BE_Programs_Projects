natural_number(0).
natural_number(s(N)):-natural_number(N).
mysubtract(N,0,N):-natural_number(N),!.
mysubtract(M,s(N),Z):-mysubtract(M,N,s(Z)).
/*
?- mysubtract(s(s(s(0))),s(0),Z).
Z = s(s(0)).

?- mysubtract(s(s(s(0))),s(s(0)),Z).
Z = s(0).

?- mysubtract(s(s(s(0))),s(s(0)),s(s(0))).
false.
*/
