maxi(X, Y, X):- X>=Y.
maxi(X, Y, Y):- X<Y.

%base_case
maxlist([X], X).

%inductive_case
maxlist([X|Rest], Max):-  maxlist(Rest, MaxRest),
			  maxi(X, MaxRest, Max).
