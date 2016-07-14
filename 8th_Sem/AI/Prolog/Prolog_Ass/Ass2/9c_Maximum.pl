/*We assumed that it is a bst*/
/*Determine Maximum Elements of a BST.*/

maxBST(t(nil,X,nil),X):-!.
maxBST(t(Left,X,nil),X):-!.
maxBST(t(Left,Root,Right),Max):- maxBST(Right,Max).

/*
?- maxBST(t(t(nil,5,nil),10,t(nil,15,nil)),X).
X = 15.
*/
