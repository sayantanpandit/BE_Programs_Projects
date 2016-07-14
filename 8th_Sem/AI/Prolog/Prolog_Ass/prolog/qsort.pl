qsort(L,M):-quicksort(L,[],M).
/*where, L is the unsorted list*/
/*M is the sorted list*/
quicksort([],A,A).
quicksort([H|T],A,M):-partition(T,Lt,H,Gt),quicksort(Gt,A,Gtsorted),quicksort(Lt,[H|Gtsorted],M).
partition([],[],_,[]). 
partition([H|T],[H|Tlt],X,Gt):-H=<X,partition(T,Tlt,X,Gt).
partition([H|T],Lt,X,[H|Tgt]):-H>X,partition(T,Lt,X,Tgt).
/*test this with:
?- qsort([2,1,3],[1,2,3]).
true .

?- qsort([2,1],[2,1]).
false.

*/
