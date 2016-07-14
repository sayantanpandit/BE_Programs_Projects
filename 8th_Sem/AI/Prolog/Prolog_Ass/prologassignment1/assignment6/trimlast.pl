trim(_,[],[]):-!.
trim(1,[X|T],T):-!.
trim(N,[H|T],T1):-N1 is N-1,trim(N1,T,T1).

trimlast(_,[],[]).
trimlast(N,L,NL):-reverse(L,R),trim(N,R,IL),reverse(IL,NL).
/*IL:-Initial list
NL:-New list*/
/*
Checking
?- trimlast(2,[a,b,c,d,e],L).
L = [a, b, c].

?- trimlast(5,[a,b,c,d,e],L).
L = [].

?- trimlast(4,[a,b,c,d,e],L).
L = [a].
*/
