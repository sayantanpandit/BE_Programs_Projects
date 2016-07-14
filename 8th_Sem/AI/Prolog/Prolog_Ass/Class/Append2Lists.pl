%base_case
append([], L, L).

%inductive_case
append([X|L1], L2, [X|L3]):- append(L1, L2, L3).

/* To test the code
?- append([1,2,3], [4,5,6], L).
L = [1, 2, 3, 4, 5, 6].
*/
