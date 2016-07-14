%base_case
reverse_List([], []).

%inductive_case
reverse_List([H|Tail], L):- reverse_List(Tail, Z),
			    append(Z, [H], L).
