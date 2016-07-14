prefix([],_):-!.
/*bace case telling that empty list is a sublist of any list*/
prefix([X|L],[X|M]):-prefix(L,M).
sublist([],_):-!.
sublist([X|L],[X|M]):-prefix(L,M),!.
sublist(L,[_|M]):-sublist(L,M).
/*Checking:
?- sublist([],[1,2]).
true.

?- sublist([1],[1,2]).
true.

?- sublist([1,2],[1,2,3]).
true.
*/
