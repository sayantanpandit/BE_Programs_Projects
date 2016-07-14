/* WAPP to Reverse a list. */

%base_case
reverse([], []).

%inductive_case
reverse([H|Tail], L):- reverse(Tail, Z),
		       append(Z, [H], L).
