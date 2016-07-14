cutlast([],[]):-!.
cutlast([X],[]):-!.
cutlast([H|T],[H|T1]):-cutlast(T,T1).
/*
Checking:-
?- cutlast([1,2,3,4,5],L).
L = [1, 2, 3, 4].

?- cutlast([],L).
L = [].

?- cutlast([1],L).
L = [].
*/

