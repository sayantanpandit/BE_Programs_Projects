%start_case
binary_tree(nil).

%inductive_case
binary_tree(t(_,L,R)) :- binary_tree(L), 
			 binary_tree(R).
/*EXAMPLE
?-binary_tree(t(a,t(b,nil,nil))).
false.

?- binary_tree(t(a,t(b,nil,nil),nil)).
true.
