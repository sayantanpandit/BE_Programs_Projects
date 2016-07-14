/*
WAPP to determine whether 2 elements are next 
to each other using append.
*/

next_to1(X,Y,L):- append(L1, [X|[Y|R]], L).

/*
?- next_to1(2 ,3, [1,2,3,5]).
true .

?- next_to1(2 ,5, [1,2,3,5]).
false.
*/
