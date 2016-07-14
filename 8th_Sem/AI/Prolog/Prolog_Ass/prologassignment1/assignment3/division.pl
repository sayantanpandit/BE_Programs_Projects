divide(N1,N2,Result):-
	integer(Result),
	Product1 is Result*N2,
	Product2 is (Result+1)*N2,
	Product1=<N1,Product2>N1,!.
/*This returns true or false*/
/*Testing:-
?- divide(15,4,Z).
false.

?- divide(15,3,5).
true.
*/
