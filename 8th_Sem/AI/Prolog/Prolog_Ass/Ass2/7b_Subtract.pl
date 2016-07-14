%start_case
subtract(N,0,N):-  natural_number(N),!.
subtract(M,s(N),Z):-subtract(M,N,s(Z)).

%base_case
natural_number(0).
%inductive_case
natural_number(s(N)):-natural_number(N).

/* OUTPUT 
subtract(s(s(0)),s(0),L).
L = s(0).

*/
