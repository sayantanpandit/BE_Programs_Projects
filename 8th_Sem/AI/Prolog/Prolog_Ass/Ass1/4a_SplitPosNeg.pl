/*
WAPP to split a list of integers such that one contains positive integers and other contains negative integers.
*/

split([], [], []).
split([H|T], [H|P], N):- H>=0, !, split(T, P, N).
split([H|T], P, [H|N]):- H<0, split(T, P, N).

/*
OUTPUT:

?- split([1, -2, 3, -4, 5, 0, 9], P, N).
P = [1, 3, 5, 0, 9],
N = [-2, -4].
*/
