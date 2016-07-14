/*
WAPP to determine whether an element is a 
member of a list using Append
*/

our_member(X, L):- append(L1, [X|L2], L).

/*
?- our_member(2, [1,5,2,3]).
true .

?- our_member(9, [1,5,2,3]).
false.
*/
