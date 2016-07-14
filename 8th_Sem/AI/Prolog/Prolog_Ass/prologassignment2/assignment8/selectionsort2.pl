myselect(_,[],[]):-!.
myselect(H,[H|T],T).
myselect(X,[H|T],[H|T1]):-myselect(X,T,T1).
selectionsort([],[]):-!.
selectionsort(L,[H|T]):-least(H,L,R),selectionsort(R,T).
least(X,L,R):-myselect(X,L,R),smaller(X,R).
/*this smaller is only to check true false*/
smaller(_,[]):-!.
smaller(X,[H|T]):-X=<H,smaller(X,T).

/*
checking:-
?- selectionsort([1,3,2,4],L).
L = [1, 2, 3, 4] ;
ERROR: =</2: Arguments are not sufficiently instantiated
*/
