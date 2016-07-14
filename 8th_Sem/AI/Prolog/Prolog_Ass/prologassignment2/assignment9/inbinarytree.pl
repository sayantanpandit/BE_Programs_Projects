in(X,t(nil,X,nil)):-!.
/*Base Case*/
in(X,t(Left,X,Right)):-!.
in(X,t(Left,Root,Right)):-in(X,Left),!;in(X,Right).
/*Why a cut in middle:-simple, because, once we check that X id in the left sub tree or not, we dont want to backtrack and check it again*/
/*Testing
?- in(d,t(t(nil,b,nil),a,t(nil,c,t(nil,d,nil)))).
true.

?- in(d,t(t(nil,b,nil),a,t(nil,c,t(nil,e,nil)))).
false.
*/
