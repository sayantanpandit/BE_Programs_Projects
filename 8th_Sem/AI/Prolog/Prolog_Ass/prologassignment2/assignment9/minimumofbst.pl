minbst(t(nil,X,nil),X):-!.
minbst(t(nil,X,Right),X):-!.
minbst(t(Left,Root,Right),Min):-minbst(Left,Min).
/*
?- minbst(t(t(nil,5,nil),10,nil),X).
X = 5.

?- minbst(t(t(nil,5,nil),10,t(nil,15,nil)),X).
X = 5.

?- minbst(t(nil,10,t(nil,15,nil)),X).
X = 10.

*/
