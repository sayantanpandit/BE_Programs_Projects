sum(0,N,N):-!.
sum(M,N,R):-M>0,M1 is M-1,sum(M1,N,R1),R is R1+1,!.
sum(M,N,R):-M<0,M1 is M+1,sum(M1,N,R1),R is R1-1.
subtract(N,0,N):-!.
subtract(M,N,R):-N>0,N1 is N-1,subtract(M,N1,R1),R is R1-1,!.
subtract(M,N,R):-N<0,N1 is N+1,subtract(M,N1,R1),R is R1+1.
multiply(0,N,0):-!.
multiply(M,N,R):-M>0,M1 is M-1,multiply(M1,N,R1),sum(R1,N,R),!.
multiply(M,N,R):-M<0,M1 is M+1,multiply(M1,N,R1),subtract(R1,N,R).
