natural_number(0).
natural_number(s(N)):-natural_number(N).
plus(0,N,N):-natural_number(N).
plus(s(M),N,s(Z)):-plus(M,N,Z).
mytimes(0,N,0) :- natural_number(N).
mytimes(s(M),N,Z) :- mytimes(M,N,W), plus(W,N,Z).
/*
?- mytimes(s(s(0)),s(s(0)),X).
X = s(s(s(s(0)))).

?- mytimes(s(s(0)),s(s(s(0))),X).
X = s(s(s(s(s(s(0)))))).
*/
