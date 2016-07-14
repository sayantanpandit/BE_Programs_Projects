sum(0,N,N):-!.
sum(M,N,R):-M>0,M1 is M-1,sum(M1,N,R1),R is R1+1,!.
sum(M,N,R):-M<0,M1 is M+1,sum(M1,N,R1),R is R1-1.
subtract(N,0,N):-!.
subtract(M,N,R):-N>0,N1 is N-1,subtract(M,N1,R1),R is R1-1,!.
subtract(M,N,R):-N<0,N1 is N+1,subtract(M,N1,R1),R is R1+1.
division(0,N,0):-!.
division(M,N,0):-M>0,N>0,M<N,!.
division(M,N,0):-M<0,N<0,M>N,!.
/*Like, if -2 is divided by -3 it will give result as 0*/
/*we are writing integer division*/
division(M,N,R):-M>0,N>0,subtract(M,N,M1),division(M1,N,R1), R is R1+1,!.
/*Now, if M is positive, we will subtract N from M
Now, Our target is to make M as 0 or less than N by subtracting N from M
that is only possible when N>0*/
division(M,N,R):-M>0,N<0,sum(M,N,M1),division(M1,N,R1), R is R1-1,!.
/*Like, division(12,-3,R). result is R=3+1
Now, 12+(-3) is 9 result is R=2+1
9+(-3) is 6  result is R=1+1
6+(-3) is 3 result is R=0+1
3+(-3) is 0 result is R=0*/
division(M,N,R):-M<0,N>0,sum(M,N,M1),division(M1,N,R1), R is R1-1,!.
division(M,N,R):-M<0,N<0,subtract(M,N,M1),division(M1,N,R1), R is R1+1.
/*see, no cut is used in the last clause. Because, last four clauses are mutually exclusive and we use cut predicate in previous 3 clauses*/
/*division(N,0,0):-write("Indefinite Result"),!.*/
/*Result:-
?- division(12,3,X).
X = 4.

?- division(13,3,X).
X = 4.

?- division(12,-3,X).
X = -4.

?- division(13,-3,X).
X = -5.

?- division(-12,3,X).
X = -4.

?- division(-13,3,X).
X = -5.

?- division(-12,-3,X).
X = 4.

?- division(-13,-3,X).
X = 4.
If you are confussionate about the last result, then remember, it is integer division, actual result is 4.33333
Now, floor(4.33333) is 4
*/


