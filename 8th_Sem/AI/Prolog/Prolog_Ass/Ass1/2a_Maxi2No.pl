maxi(X, X, X).

maxi(X, Y, X):- X>=Y, !.
maxi(X, Y, Y):- X<Y.
