/*
WAPP to determine whether a list is not a two-elements list.
*/

%base_case
no_doubleton([]).
no_doubleton([X]).

%inductive_case
no_doubleton([X|[Y|[Z|Rest]]]).

/*
?- no_doubleton([1,1,2,3]).
true.

?- no_doubleton([1,2]).
false.

?- no_doubleton([1]).
true .

?- no_doubleton([]).
true.
*/
