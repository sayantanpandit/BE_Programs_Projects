/*
WAPP to determine whether a list is not a two-element list.
*/

%base_case
no_doubleton([]).
no_doubleton([X]).

%inductive_case
no_doubleton([X|[Y|[Z|Rest]]]).
