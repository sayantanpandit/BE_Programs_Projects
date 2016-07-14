/*
Remove Duplicate Elements from a list.
*/

/*OUR_MEMBER CODE*/
%base_case
our_member(X, [X|_]):- !.
%inductive_case
our_member(X, [_|Y]):- our_member(X, Y).


%base_case
removeDup([],[]).
%inductive_case       
removeDup([H|T], X):- our_member(H,T),
		      !,
		      removeDup(T,X).

removeDup([H|T],[H|X]):- removeDup(T,X).
