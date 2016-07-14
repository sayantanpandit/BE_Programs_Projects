/*Delete all the occurrences of an element from a list*/
mydelete(_,[],[]).
mydelete(A,[A|L],M):-!,mydelete(A,L,M).
mydelete(A,[B|L],[B|M]):-mydelete(A,L,M).
/*Testing it:
?- mydelete(c,[a,v,c,s,d,c,w,a],L).
L = [a, v, s, d, w, a] ;
*/
