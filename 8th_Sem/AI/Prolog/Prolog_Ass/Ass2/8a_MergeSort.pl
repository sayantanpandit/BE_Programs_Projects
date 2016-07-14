/* MERGE SORT */

/* MERGESORT CODE*/
mergesort([],[]):- !. 
mergesort([X],[X]):- !.
mergesort(List, SortedList):- divide(List, List1, List2), 
			      mergesort(List1, SortedList1), 
			      mergesort(List2, SortedList2), 
			      merge(SortedList1, SortedList2, SortedList). 

/* DIVIDE the list*/			      
divide([],[],[]):- !. 
divide([X],[X],[]):-!.
divide([X|[Y|Rest]], [X|L1], [Y|L2]):- divide(Rest, L1, L2). 

/* MERGE the list after sorting */
merge([],[],[]):-!. 
merge(X,[],X):-!. 
merge([],X,X):-!. 
merge([X|L1], [Y|L2], [X|L3]):- X<Y,!, merge(L1,[Y|L2],L3). 
merge([X|L1], [Y|L2], [Y|L3]):- X>Y,!, merge([X|L1],L2,L3).
merge([X|L1], [Y|L2], [X|[Y|L3]]):- X=Y,!, merge(L1,L2,L3).


/*
?- mergesort([13,5,69,12], L).
L = [5, 12, 13, 69].

?- mergesort([13,5,6, 9,12, -9, -1], L).
L = [-9, -1, 5, 6, 9, 12, 13].
*/
