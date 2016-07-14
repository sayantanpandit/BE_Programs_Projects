/* UNION between two sets. */

%base_case
union([], L, L).

%inductive_case
union([X|L1], L2, L3):- our_member(X, L2), 
			union(L1, L2, L3).

union([X|L1], L2, [X|L3]):- union(L1, L2, L3).


%base_case
our_member(X, [X|_]):- !.

%inductive_case
our_member(X, [_|Y]):- our_member(X, Y).
/*
Run : swipl -s SetUnion.pl SetMembership.pl

OUTPUT :
?- union([a,b,c], [d,f,a], L).
L = [b, c, d, f, a] .

?- union([a,b,c], [d,f,p], L).
L = [a, b, c, d, f, p].
*/
