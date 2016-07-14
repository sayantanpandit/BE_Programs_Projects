fact1(N,Ans):-factacc(N,1,Ans).
factacc(0,A,A).
factacc(N,A,Ans):-N1 is N-1,A1 is A*N,factacc(N1,A1,Ans).
