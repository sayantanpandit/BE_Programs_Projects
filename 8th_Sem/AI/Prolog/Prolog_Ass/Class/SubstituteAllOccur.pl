/*
To substitute all occurances of an element by another
element in a list.
*/

%base_case
substitute(_, [], _, []).

%for_empty_list
substitute(A, [A|L], B, [B|M]):- !, substitute(A, L, B, M).

substitute(A, [X|L], B, [X|M]):- substitute(A, L, B, M).

/*
Output:
?- substitute(5, [1,2,5,6,5,3], 4, L).
L = [1, 2, 4, 6, 4, 3] .
*/
