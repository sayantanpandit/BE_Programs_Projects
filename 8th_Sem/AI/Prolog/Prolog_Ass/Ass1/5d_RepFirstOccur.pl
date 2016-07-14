/*
To replace the first occurence of X in L with Y, giving the 
result in L1.
*/

%base_Case
repFirst(_, [], _, []):- !.

%inductive_case
repFirst(X, [X|T], Y, [Y|T]):- !.

repFirst(X, [H|T], Y, [H|T1]):- repFirst(X, T, Y, T1).

/*
OUTPUT
?- repFirst(5, [1,2,3,5,6,5], 4, L).
L = [1, 2, 3, 4, 6, 5].
*/
