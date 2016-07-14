%base_case
append([], L, L).

%inductive_case
append([X|L1], L2, [X|L3]):- append(L1, L2, L3).
