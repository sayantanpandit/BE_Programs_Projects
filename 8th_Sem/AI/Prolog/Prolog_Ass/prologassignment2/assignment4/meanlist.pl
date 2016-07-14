sumlist([],0):-!.
sumlist([X],X):-!.
sumlist([H|T],Sum):-sumlist(T,SumTail), Sum is SumTail+H.
lengthlist([],0):-!.
lengthlist([H|T],R):-lengthlist(T,R1), R is R1+1.
meanlist([],0):-!.
/*otherwise, for empty list thee result will be indefinite*/
meanlist(L,X):-sumlist(L,Sum),lengthlist(L,Length), X is Sum/Length.
/*
?- meanlist([],X).
X = 0.

?- meanlist([1],X).
X = 1.

?- meanlist([1,2],X).
X = 2.5.
*/
