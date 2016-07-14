replace(_,_,[],_,[]):-!.
/*that means if nth occurrence of an element needs to be replaced by another element in an empty list, the result will be an empty list*/
replace(1,X,[X|T],Y,[Y|T]):-!.
replace(N,X,[X|T],Y,[X|T1]):-N1 is N-1,replace(N1,X,T,Y,T1),!.
replace(N,X,[H|T],Y,[H|T1]):-replace(N,X,T,Y,T1).
/*
Check:
?- replace(2,a,[b,a,b,a,c,d],e,L).
L = [b, a, b, e, c, d].

?- replace(1,a,[b,a,b,a,c,d],e,L).
L = [b, e, b, a, c, d].

?- replace(3,a,[b,a,b,a,c,d],e,L).
L = [b, a, b, a, c, d].

?- replace(0,a,[b,a,b,a,c,d],e,L).
L = [b, a, b, a, c, d].

?- replace(2,a,[a,b,a,c,d],e,L).
L = [a, b, e, c, d].
*/
