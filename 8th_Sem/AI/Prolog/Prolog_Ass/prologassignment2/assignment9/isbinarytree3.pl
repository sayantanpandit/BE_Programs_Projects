binary_tree(nil):-!.
binary_tree(t(Left,Root,Right)) :- binary_tree(Left),!, binary_tree(Right).
/*The cut is like a switch, If binary_tree(Left) returns true, then the cut will allow to check if the right subtree is also a binary_tree and if right subtree is a binary tree or is not a binary tree, the program will not backtrack to check again if the left subtree is a binary tree or not*/
/*
Checking:-
?- binary_tree(t(t(t(nil,d,nil),a,nil),b,t(nil,c,nil))).
true.

?-  binary_tree(t(t(t(nil,d,nil),a,nil),b,t(nil,c))).
false.
*/
