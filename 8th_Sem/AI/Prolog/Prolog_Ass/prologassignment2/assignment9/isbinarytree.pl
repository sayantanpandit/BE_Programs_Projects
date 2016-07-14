binary_tree(nil).
binary_tree(t(_,L,R)) :- binary_tree(L), binary_tree(R).
/*check
?-binary_tree(t(a,t(b,nil,nil))).
false.
?- binary_tree(t(a,t(b,nil,nil),nil)).
true.



