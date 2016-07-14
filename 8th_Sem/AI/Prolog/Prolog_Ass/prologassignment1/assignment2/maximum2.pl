maximum(X,Y,X):-X>=Y,!.
maximum(X,Y,Y):-X<Y.
/*
?- maximum(4,4,X).
X = 4.

?- maximum(2,4,X).
X = 4.

?- maximum(4,2,X).
X = 4.

?- maximum(3,2,X).
X = 3.
*/

