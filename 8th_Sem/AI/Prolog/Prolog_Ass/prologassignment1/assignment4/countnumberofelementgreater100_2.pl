count(L,Result):-countacc(L,0,Result).
countacc([],A,A).
countacc([H|T],A,Result):-H>100,!,A1 is A+1,countacc(T,A1,Result).
countacc([H|T],A,Result):-countacc(T,A,Result).
/*
?- count([10,100,101,90,110,105,5],X).
X = 3.

?- count([0,0,100],X).
X = 0.

?- count([100],X).
X = 0.

?- count([],X).
X = 0.
*/
