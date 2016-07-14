/*We assumed that it is a bst*/
maxbst(t(nil,X,nil),X):-!.
maxbst(t(Left,X,nil),X):-!.
maxbst(t(Left,Root,Right),Max):-maxbst(Right,Max).
/*
?- maxbst(t(t(nil,5,nil),10,t(nil,15,nil)),X).
X = 15.

?- maxbst(t(t(nil,5,nil),10,nil),X).
X = 10.
*/
