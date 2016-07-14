in(X,t(nil,X,nil)):-!.
in(X,t(Left,X,Right)):-!.
in(X,t(Left,Root,Right)):-X<Root,in(X,Left),!;X>Root,in(X,Right).
/*; means or*/

/*
Checking:
?- in(15,t(t(nil,5,nil),10,t(nil,15,nil))).
true.

?- in(20,t(t(nil,5,nil),10,t(nil,15,nil))).
false.

?- in(20,t(t(nil,5,nil),10,t(nil,15,t(nil,20,nil)))).
true.
*/
