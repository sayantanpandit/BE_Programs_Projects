length3(L,N):-lengthacc(L,0,N).
/*lengthacc(L,0,N):*/
lengthacc([],A,A).
/*i.e. return the initial value of accumulator here*/
lengthacc([H|T],A,N):-A1 is A+1, lengthacc(T,A1,N).
