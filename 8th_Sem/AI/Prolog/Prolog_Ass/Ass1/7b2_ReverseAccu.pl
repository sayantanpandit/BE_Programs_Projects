/*
Reverse a list using an accumulator.
*/

%start_case
reverseAccu(L1, L2):- reverseUsnAcc(L1, [], L2).

%base_case
reverseUsnAcc([], L, L).

%inductive_case
reverseUsnAcc([X|L1], L2, L3):- reverseUsnAcc(L1, [X|L2], L3).

/*
OUTPUT
?- reverseAccu([4,3,2,1,8,4,6], L).
L = [6, 4, 8, 1, 2, 3, 4].

?- reverseAccu([4,3,2,1], L).
L = [1, 2, 3, 4].
*/
