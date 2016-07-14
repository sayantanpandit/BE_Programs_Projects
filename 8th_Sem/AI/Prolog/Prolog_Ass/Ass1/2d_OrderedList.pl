/*Determine whether a list is ordered (ascending)*/

%base_case
ordered([]).
ordered([X]).

%inductive_case
ordered([X|[Y|Rest]]):- X=<Y, ordered([Y|Rest]).

/*
?- ordered([1,2,2,3,5]).
true .

?- ordered([1,2,2,6,5]).
false.

?- ordered([1,2,3,5]).
true .
*/
