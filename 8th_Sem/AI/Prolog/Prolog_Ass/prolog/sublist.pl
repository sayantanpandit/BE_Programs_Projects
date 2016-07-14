prefix([],_).
prefix([X|L],[X|M]):-prefix(L,M).
/*A sublist is a sublist of another list if occurs in the second list consecutively in the same order*/
sublist([],_).
/*i.e. empty list is a sublist of every list*/
sublist([X|L],[X|M]):-prefix(L,M),!.
/*i.e. if both list has X as first element then check the rest of the list for prefix matching*/
sublist(L,[_|M]):-sublist(L,M).
/*
Testing it:
?- sublist([b,c,d],[a,b,c,d,e,f,g]).
true.

?- sublist([b,f,d],[a,b,c,d,e,f,g]).
false.
*/
