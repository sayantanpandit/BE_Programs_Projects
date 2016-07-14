maximum(X,Y,X):-X>=Y.
/*i.e. if X>=Y then inputs will be X and Y and output will be X*/
maximum(X,Y,Y):-X<Y.
maxlist([X],X).
maxlist([X|Rest],Max):-maxlist(Rest,MaxRest),maximum(X,MaxRest,Max).


