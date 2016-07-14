
facto(0,1).
facto(N,Ans):- N1 is N-1,
	       facto(N1,A1),
	       Ans is A1*N.
	       
/*OUTPUT*/
/*
?- facto(5, Ans).
Ans = 120 .
*/	       
