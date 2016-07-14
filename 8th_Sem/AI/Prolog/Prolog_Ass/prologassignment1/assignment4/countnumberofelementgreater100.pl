count([],0).
count([H|T],C):-H>100,!,count(T,C1),C is C1+1.
count([H|T],C):-count(T,C).
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
