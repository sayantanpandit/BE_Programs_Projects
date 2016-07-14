efface(_,[],[]):-!.
efface(A,[A|L],L):-!.
/*make it parmanet using cut otherwise during baccktracking prolog will try to find an alternative solution
So, here, we are restricting prolog to make any alternative choice*/
efface(A,[B|L],[B|M]):-efface(A,L,M).
/*
?- efface(a,[a,b,c],L).
L = [b, c].

?- efface(a,[b,c],L).
L = [b, c].

?- efface(a,[],L).
L = [].

?- efface(a,[a],L).
L = [].
*/
