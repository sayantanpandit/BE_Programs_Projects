delnlist(_,[],[]):-!.
delnlist(1,[H|T],T):-!.
delnlist(N,[H|T],[H|T1]):-N1 is N-1,delnlist(N1,T,T1).
/*
?- delnlist(5,[a,b,e,c,d,w,r],L).
L = [a, b, e, c, w, r].

?- delnlist(4,[a,b,e,c,d,w,r],L).
L = [a, b, e, d, w, r].

?- delnlist(4,[a,b,e],L).
L = [a, b, e].

?- delnlist(4,[],L).
L = [].

?- delnlist(0,[],L).
L = [].

?- delnlist(1,[a],L).
L = [].
*/
