maximum(X,Y,X):-X>=Y,!.
/*i.e. if X>=Y then inputs will be X and Y and output will be X*/
maximum(X,Y,Y).
maxlist([X],X):-!.
maxlist([X|Rest],Max):-maxlist(Rest,MaxRest),maximum(X,MaxRest,Max).
/*
Checking:
?- maxlist([1,2,2,4,2,3,5],X).
X = 5.

?- maxlist([1],X).
X = 1.

?- maxlist([1,1],X).
X = 1.

?- maxlist([1,2],X).
X = 2.

?- maxlist([],X).
false.

?- maxlist([1],X).
X = 1.

*/

