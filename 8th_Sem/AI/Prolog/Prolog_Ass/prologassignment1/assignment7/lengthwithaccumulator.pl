mylength(L,N):-lengthacc(L,0,N).
/*this is the relation between mylength and lengthacc
now, lengthacc(L,A,N) means the length of the list L when added to the number A (accumulator content), is the number N*/
lengthacc([],A,A).
/*that means if the list is empty, the length of the list is the value which is so far accumulated*/
lengthacc([H|T],A,N):- A is A1+1,lengthacc(T,A1,N).
