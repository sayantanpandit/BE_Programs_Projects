replace(_,[],_,[]):-!.
replace(1,[X],Y,[Y]):-!.
replace(1,[X|L],Y,[Y|L]):-!.
replace(N,[H|L],Y,[H|L1):-N1 is N-1,replace(N1,L,Y,L1).
replace(N,[X|L],Y,[X|L1]):-N1 is N-1,replace(N1,L,Y,L1).
/*
?- replace(1,[],a,L).
L = [].

?- replace(1,[a],b,L).
L = [b].

?- replace(2,[b,a,d],c,L).
L = [b, c, d].
*/
