order([]):-!.
order([X]):-!.
order([X|[Y|Rest]]):-X=<Y,order([Y|Rest]).
/*Withoutt any cut,
?- order([1,2,3]).
true ;
false.

?- order([1,2]).
true ;
false.

?- order([1]).
true ;
false.

?- order([]).
true.
*/
/*With cuts:-
?- order([1,2,3]).
true ;
false.

?- order([1,2]).
true ;
false.

?- order([1]).
true ;
false.

?- order([]).
true.
*/
