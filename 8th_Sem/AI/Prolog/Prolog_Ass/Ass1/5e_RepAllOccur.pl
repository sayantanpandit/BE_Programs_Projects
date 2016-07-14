/*
To replace all occurrences of X in L with Y, giving
the result in L1.
*/

%base_case
repAll(_, [], _, []):-!.

%inductive_case
repAll(X, [X|T], Y, [Y|T1]):- repAll(X, T, Y, T1),!.

repAll(X, [H|T], Y, [H|T1]):- repAll(X, T, Y, T1).

/*
OUTPUT
?- repAll(5, [1,2,3,5,6,5], 4, L).
L = [1, 2, 3, 4, 6, 4].
*/
