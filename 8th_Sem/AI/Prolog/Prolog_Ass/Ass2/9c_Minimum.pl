/*Determine MINIMUM Element of a BST. */

minBST(t(nil,X,nil),X):-!.
minBST(t(nil,X,Right),X):-!.
minBST(t(Left,Root,Right),Min):- minBST(Left,Min).

/*
?- minBST(t(t(nil,5,nil),10,nil),X).
X = 5.
*/
