replace(_,[],_,[]):-!.
replace(X,[X|T],Y,[Y|T1]):-replace(X,T,Y,T1),!.
replace(X,[H|T],Y,[H|T1]):-replace(X,T,Y,T1).
/*
?- replace(a,[b,c,a,d,e,a],f,L).
L = [b, c, f, d, e, f].

?- replace(a,[a],f,L).
L = [f].

?- replace(a,[],f,L).
L = [].

?- replace(a,[a,a,a,a,a,a],f,L).
L = [f, f, f, f, f, f].
*/
