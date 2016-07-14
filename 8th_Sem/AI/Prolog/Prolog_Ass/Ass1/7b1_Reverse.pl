/*
 Reverse a list without using an accumulator.
*/

/*Reverse Code*/
%base_case
reverse_List([], []).

%inductive_case
reverse_List([H|Tail], L):- reverse_List(Tail, Z),
			    append(Z, [H], L).

/*Append Code*/
%base_case
append([], L, L).

%inductive_case
append([X|L1], L2, [X|L3]):- append(L1, L2, L3).

/*  OUTPUT
?- reverse_List([4,3,2,1], L).
L = [1, 2, 3, 4].

?- reverse_List([4,3,2,1,8,4,6], L).
L = [6, 4, 8, 1, 2, 3, 4].
*/
