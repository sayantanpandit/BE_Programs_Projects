%base_case
next_to1(X, Y, [X|[Y|Rest]]).

%inductive_case
next_to1(X, Y, [Z|Rest]):- next_to1(X, Y, Rest).
