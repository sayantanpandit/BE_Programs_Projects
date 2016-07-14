/*
Suppose that L1 and L2 are lists of numeric values. 
WAPP to determine the Inner_product (L1, L2, X) that
defines X to be inner product of two vectors L1, L2.
*/

%base_case
innerproduct([], _, 0):- !.
innerproduct(_, [], 0):- !.

%inductive_case
innerproduct([H1|T1],[H2|T2],X):- innerproduct(T1,T2,X1),
				  X is X1+H1*H2.
/*?- 
?- innerproduct([2,3], [4,5], L).
L = 23.

?- innerproduct([2], [4,5], L).
L = 8.
*/
