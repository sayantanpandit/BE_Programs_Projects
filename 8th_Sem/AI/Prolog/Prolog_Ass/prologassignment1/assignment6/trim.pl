trim(_,[],[]):-!.
trim(1,[X|T],T):-!.
trim(N,[H|T],T1):-N1 is N-1,trim(N1,T,T1).
/*
?- trim(1,[2,3,4],L).
L = [3, 4].

?- trim(3,[2,3,4],L).
L = [].

?- trim(3,[2],L).
L = [].
*/


