/*
WAPP to determine whether the first two elements of a list 
are same.
*/

double_header([X|[X|Rest]]).

/*
OUTPUT:
?- double_header([1,1,2,3]).
true.

?- double_header([1,9,2,3]).
false.
*/
