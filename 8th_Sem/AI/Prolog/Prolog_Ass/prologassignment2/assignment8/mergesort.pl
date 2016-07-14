mergesort([],[]):-!. 
mergesort([X],[X]):-!.
 mergesort(List, SortedList):- divide(List, List1, List2), mergesort(List1, SortedList1), mergesort(List2, SortedList2), merge(SortedList1, SortedList2, SortedList). 
divide([],[],[]):-!. 
divide([X],[X],[]):-!.
 divide([X|[Y|Rest]], [X|L1], [Y|L2]):- divide(Rest, L1, L2). 
merge([],[],[]):-!. 
merge(X,[],X):-!. 
merge([],X,X):-!. 
merge([X|L1], [Y|L2], [X|L3]):- X<Y,!, merge(L1,[Y|L2],L3). 
merge([X|L1], [Y|L2], [Y|L3]):- X>Y,!, merge([X|L1],L2,L3).
merge([X|L1], [Y|L2], [X|[Y|L3]]):- X=Y,!, merge(L1,L2,L3).
/*
?- mergesort([1,2,4,3],L).
L = [1, 2, 3, 4].

?- mergesort([1,5,4,3],L).
L = [1, 3, 4, 5].

?- mergesort([2],L).
L = [2].
*/
