replist(_,[],_,[]):-!.
replist(X,[X|T],Y,[Y|T]):-!.
replist(X,[H|T],Y,[H|T1]):-replist(X,T,Y,T1).
/*
?- replist(a,[],b,L).
L = [].

?- replist(a,[a],b,L).
L = [b].

?- replist(a,[b,a,c],b,L).
L = [b, b, c].
*/
