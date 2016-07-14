%base_case
our_member(X, [X|Rest]).

%inductive_case
our_member(X, [Y|Rest]):- our_member(X, Rest).

/*To run the code
?- our_member(2, [1,2,3,7]).
true .

?- our_member(6, [1,2,3,7]).
false.
*/
