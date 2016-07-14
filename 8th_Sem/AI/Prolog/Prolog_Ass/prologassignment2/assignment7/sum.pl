natural_number(0).
natural_number(s(N)) :- natural_number(N).
plus(0,N,N) :- natural_number(N).
plus(s(M),N,s(Z)) :- plus(M,N,Z).

/*
?- plus(s(0),s(s(0)),L).
L = s(s(s(0))).

?- plus(s(0),0,L).
L = s(0).

?- plus(s(0),s(0),L).
L = s(s(0)).
*/

