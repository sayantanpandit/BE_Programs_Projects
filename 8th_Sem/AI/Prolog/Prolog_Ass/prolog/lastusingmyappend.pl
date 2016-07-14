myappend([],L,L).
myappend([X|L1],L2,[X|L3]):-myappend(L1,L2,L3).
mylast(L,X):-myappend(L1,[X],L).
/*
?- mylast([a,b,c,d],d).
true .

?- mylast([a,b,c,d],c).
false.
*/
