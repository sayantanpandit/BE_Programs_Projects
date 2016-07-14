/*
WAPP to determine whether two lists are of same length.
*/

%base_case
samelength([], []).

%inductive_case
samelength([X|Rest1], [Y|Rest2]):- samelength(Rest1, Rest2). 
