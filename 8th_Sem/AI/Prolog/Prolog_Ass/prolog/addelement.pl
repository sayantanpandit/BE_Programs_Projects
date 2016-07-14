/*Adding an element to the beginning of list*/
our_member(X,[X|Rest]).
/*This is base case, i.e. if X is found at the beginning of list, then obviously X is a member of the list*/
our_member(X,[Y|Rest]):-our_member(X,Rest).
our_add(A,[],[A]).
/*this is the base case, i.e.if A is added to an empty list, A will be the first element of the list*/
our_add(A,L,L):-our_member(A,L),!.
/*i.e. if A is already a member of the the List, then do not do anything*/
/*and stop the recursion there*/
/*otherwise, add it at the beginning of the list since it is already checked that A is not a member of the List*/
our_add(A,L,[A|L]). 
/*Testing it:-
?- our_add(a,[b,c],L).
L = [a, b, c].
*/
