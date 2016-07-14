/*
WAPP to determine the length of the list
*/

length([], 0).
length([H|T], S(N)):- length(T, N).
