mysum([],0).
mysum([H|T],Sum):-mysum(T,Sumtail), Sum is H+Sumtail.
/*
?- mysum([1,2],X).
X = 3.

?- mysum([1],X).
X = 1.

?- mysum([2,1,3],X).
X = 6.

?- mysum([],X).
X = 0.

?- mysum([0],X).
X = 0.
*/
