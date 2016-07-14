/* Problem in some test cases*/

merge([],[],[]):-!.
merge(X,[],X):-!.
merge([],X,X):-!.
merge([X|L1],[Y|L2],[X|L3]):-X<Y,!,merge(L1,[Y|L2],L3).
merge([X|L1],[Y|L2],[Y|L3]):-X>Y,!,merge([X|L1],L2,L3).
merge([X|L1],[Y|L2],[X|[Y|L3]]):-X=Y,merge(L1,L2,L3).

/*
?- merge([2,1], [6,3], L).
L = [2, 1, 6, 3].

?- merge([1,4], [2,3], L).
L = [1, 2, 3, 4].

*/
