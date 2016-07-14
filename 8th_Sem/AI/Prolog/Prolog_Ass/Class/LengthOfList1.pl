/*
WAPP to determine the length of the list without pre-defined function.
*/

%base_case
my_length([], 0).

%inductive_case
my_length([H|T], s(N)):- my_length(T, N).
