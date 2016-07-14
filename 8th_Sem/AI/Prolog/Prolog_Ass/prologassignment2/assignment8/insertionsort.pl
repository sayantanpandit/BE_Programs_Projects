insert(X, [], [X]):-!.
insert(X, [H|T], [X|L]):- X =< H,!, insert(H, T, L).
insert(X, [H|T], [H|L]):- X > H, insert(X, T, L).
insertionSort([], []):-!.
insertionSort([H|T], R):- insertionSort(T, W), insert(H, W, R).
/*
?- insertionSort([1,4,3,2],L).
L = [1, 2, 3, 4].

?- insertionSort([1,4,5,3,2],L).
L = [1, 2, 3, 4, 5].

?- insertionSort([1,4,4,3,2],L).
L = [1, 2, 3, 4, 4].

?- insertionSort([1,2,3,4],L).
L = [1, 2, 3, 4].
*/
