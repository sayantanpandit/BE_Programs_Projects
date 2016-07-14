/* QUICK SORT using accumulator. */

/* qsort(Xs, Ys) is true if 
   Ys is a sorted permutation of the list Xs. */

%start_case   
qsort(Xs, Ys):- quicksort(Xs, Ys, []).

%base_case
quicksort([], Ys, Ys).
%inductive_case
quicksort([X|Xs], Ys, Zs):- partition(Xs, X, Ms, Ns),
			    quicksort(Ns, Ws, Zs),
			    quicksort(Ms, Ys, [X|Ws]).
  
/* partition(Ls, X, Ms, Ns) is true if the list Ms contains 
   the elements of the list Ls which are less than or equal to X, and
   the list Ns contains the elements of Ls which are greater than X. */
partition([K|L], X, M, [K|N]):-  X < K, 
				 !,  
				 partition(L, X, M, N).
				 
partition([K|L], X, [K|M], N):-  partition(L, X, M, N).
partition([], _, [], []).

/* OUTPUT
?- qsort([3,1,2,5,4], [1,2,3,4,5]).
true.

?- qsort([3,1,2,5,4], [1,2,3,4,5,6]).
false.

?- qsort([3,1,2,5,4], [1,2,3,5,4]).
false. 
*/
