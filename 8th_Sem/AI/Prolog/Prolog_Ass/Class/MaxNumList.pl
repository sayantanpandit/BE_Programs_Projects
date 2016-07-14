/* To find the maximum number in a list */
maxi(X, Y, X):- X>=Y.
maxi(X, Y, Y):- X<Y.

%base_case
maxlist([X], X).

%inductive_case
maxlist([X|Rest], Max):- maxlist(Rest, MaxRest),
			 maxi(X, MaxRest, Max).
			 
/*
?- maxlist([1,2,3,6,5], X).
X = 6 .

?- maxlist([1,2,3,-6,5], X).
X = 5 .
*/			 
