/*Delete all the occurrences of an element from a list*/
mydelete(_,[],[]):-!.
mydelete(A,[A|L],M):-!,mydelete(A,L,M).
mydelete(A,[B|L],[B|M]):-mydelete(A,L,M).
/*In last clause we dont need any cut since, last two clauses are exclusive*/
/*Testing it:
?- mydelete(a,[a],L).
L = [].

?- mydelete(a,[a,b,a,c,d],L).
L = [b, c, d].

?- mydelete(a,[],L).
L = [].

*/
