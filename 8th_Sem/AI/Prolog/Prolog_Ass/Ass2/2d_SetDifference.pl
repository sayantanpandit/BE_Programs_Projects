/* SET DIFFERENCE */

%base_case
difference([], L, []).

%inductive_case
difference([X|L1], L2, L3):- our_member(X, L2), 
			     difference(L1,L2, L3).

difference([X|L1], L2, [X|L3]):- difference(L1, L2, L3).

%base_case
our_member(X, [X|_]):- !.

%inductive_case
our_member(X, [_|Y]):- our_member(X, Y).
/*
RUN--> swipl -s SetDifference.pl SetMembership.pl

OUTPUT:
?- difference([a,c,b,f], [d,c,f,e], L).
L = [a, b] .
*/
