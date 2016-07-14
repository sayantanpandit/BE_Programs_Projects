/* SET DIFFERENCE */

%base_case
difference([], L, []).

%inductive_case
difference([X|L1], L2, L3):- our_member(X, L2), 
			     difference(L1,L2, L3).

difference([X|L1], L2, [X|L3]):- difference(L1, L2, L3).

/*
RUN--> swipl -s SetDifference.pl SetMembership.pl

OUTPUT:
?- difference([a,c,b,f], [d,c,f,e], L).
L = [a, b] .
*/
