prefix([],_).
prefix([X|L],[X|M]):-prefix(L,M).
/*?-
testing it
 prefix([a,b],[a,b,c,d]).
true.

?- prefix([b,c],[a,b,c,d]).
false.
*/
