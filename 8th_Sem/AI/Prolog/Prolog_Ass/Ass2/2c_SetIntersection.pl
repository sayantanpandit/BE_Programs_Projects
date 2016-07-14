/* SET INTERSECTION */

%base_case
intersection([], L, []).

%inductive_case
intersection([X|L1], L2, [X|L3]):- our_member(X, L2), 
				   !,
				   intersection(L1, L2, L3).
				   
intersection([X|L1], L2, L3):- intersection(L1,L2,L3).

%base_case
our_member(X, [X|_]):- !.

%inductive_case
our_member(X, [_|Y]):- our_member(X, Y).			   
/* OUTPUT 
?- intersection([a, b, c, d], [c, d, e, f], L).
L = [c, d].
*/				   
