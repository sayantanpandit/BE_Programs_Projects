/*
WAPP to Interleave alternate elements of L1 and L2 into L. 
For example, if L1= [a, b, c] and L2= [1, 2], 
 	     then L= [a, 1, b, 2, c].
*/

interleave([],[],[]):- !.
interleave(L,[],L):- !.
interleave([],L,L):- !.
interleave([H1|L1],[H2|L2],[H1|[H2|L]]):- interleave(L1,L2,L).

/*
?- interleave([a,b,c], [1,2,3], L).
L = [a, 1, b, 2, c, 3].

?- interleave([], [1], L).
L = [1].

?- interleave([], [1,2], L).
L = [1, 2].

?- interleave([a], [1,2], L).
L = [a, 1, 2].

?- interleave([a,b], [1], L).
L = [a, 1, b].
*/
