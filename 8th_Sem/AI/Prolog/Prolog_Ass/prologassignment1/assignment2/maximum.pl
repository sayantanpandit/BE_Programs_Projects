maximum(X,Y,X):-X>=Y.
maximum(X,Y,Y):-X<Y.
/*
?- maximum(2,3,X).
X = 3.

?- maximum(4,3,X).
X = 4 ;
false.
?- maximum(4,4,X).
X = 4 ;
false.
*/
