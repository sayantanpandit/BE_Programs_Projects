/*
To determine whether a list is a sublist of another list.
*/

%base_case
sublist([], _).

%inductive_case
sublist([X|L], [X|M]):- prefix(L, M), 
			!,
			sublist(L, M).
			
prefix([], _).
prefix([X|L], [X|M]):- prefix(L, M).

/*
Output:
?- sublist([1,2,3], [1,2,3,2,9,3]).
true.
*/			
