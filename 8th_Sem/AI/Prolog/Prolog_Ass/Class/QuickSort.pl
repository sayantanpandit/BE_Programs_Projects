/* QUICKSORT */

/*L-UnSorted List    M->Sorted List*/
qsort(L, M):- quicksort(L, [], M). 

%base_case
quicksort([], A, A).

%inductive_case
quicksort([H|T], A, M):- partition(T, Lt, H, Gt), 
			 quicksort(Gt, R, Gsorted), 
			 quicksort(Lt, [H|Gsorted], M).


%base_case
partition([], [], _, []).

%inductive_case
partition([H|T], [H|TLt], X, Gt):- H=<X, 
				   !, 
				   partition(T, TLt, X, Gt).

partition([H|T], Lt, X, [H|TGt]):- H>X, 
				   partition(T, Lt, X, TGt).
