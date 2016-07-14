fact(0,1).
fact(N,Ans):-N1 is N-1,fact(N1,A1),Ans is A1*N.
