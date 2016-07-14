append([],L,L).
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).
/*
Checking:
?- append([],[2,3],L).
L = [2, 3].

?- append([1,2],[2,3],L).
L = [1, 2, 2, 3].

?- append([1,2],[],L).
L = [1, 2].

?- append([1,2],[3,4],L).
L = [1, 2, 3, 4].
*/
