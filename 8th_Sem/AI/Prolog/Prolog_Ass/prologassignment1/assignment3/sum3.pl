plus(0,N,N):-!.
plus(M,N,Result):-M>0,!,M1 is M-1,plus(M1,N,Result1),Result is Result1+1.
plus(M,N,Result):-M<0,!,M1 is M+1,plus(M1,N,Result1),Result is Result1-1.
