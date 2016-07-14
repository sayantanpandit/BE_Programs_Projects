/* SET MEMBERSHIP */

%base_case
our_member(X, [X|_]):- !.

%inductive_case
our_member(X, [_|Y]):- our_member(X, Y).

/*
Output:
?- our_member(5, [1,2, 6, 5, 4]).
true.

?- our_member(7, [1,2, 6, 5, 4]).
false.
*/
