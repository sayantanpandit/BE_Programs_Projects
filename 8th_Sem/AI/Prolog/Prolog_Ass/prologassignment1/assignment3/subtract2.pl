subtract(N,0,N):-!.
subtract(M,N,R):-N>0,N1 is N-1,subtract(M,N1,R1),R is R1-1,!.
subtract(M,N,R):-N<0,N1 is N+1,subtract(M,N1,R1),R is R1+1.
/*
?- subtract(2,-3,X).
X = 5.

?- subtract(2,3,X).
X = -1.

?- subtract(-2,3,X).
X = -5.

?- subtract(-2,-3,X).
X = 1.
*/
