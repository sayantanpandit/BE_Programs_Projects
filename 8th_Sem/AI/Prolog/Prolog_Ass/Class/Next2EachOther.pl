%base_case
next_to1(X, Y, [X|[Y|Rest]]).

%inductive_case
next_to1(X, Y, [Z|Rest]):- next_to1(X, Y, Rest).

/*
To run the code:
?- next_to1(2, 3, [1,2,3,4]).
true .
?- next_to1(2, 8, [1,2,3,4]).
false.
*/
