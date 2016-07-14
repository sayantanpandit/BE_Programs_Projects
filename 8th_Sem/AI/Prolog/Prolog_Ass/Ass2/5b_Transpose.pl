/*
WAPP to Transpose L1, L2 into L. 
For Example, if L1= [a, b, c] and L2= [1, 2, 3], 
	     then L= [(a, 1), (b, 2), (c, 3)].
*/

%base_case
transpose([],[],[]).

%inductive_case
transpose([H1|L1],[H2|L2],[(H1,H2)|L]):- transpose(L1,L2,L).

/*
?- transpose([a,b,c], [1,2,3], L).
L = [ (a, 1), (b, 2), (c, 3)].

?- transpose([1], [a], L).
L = [ (1, a)].

?- transpose([1,3], [2,4], L).
L = [ (1, 2), (3, 4)].

?- transpose([1,3, 5], [2,4,6], L).
L = [ (1, 2), (3, 4), (5, 6)].
*/
