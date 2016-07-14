count(0,0).
count(s(N),R):-count(N,R1),R is R1+1.
/*dont know how to represent negative number in this number system*/
