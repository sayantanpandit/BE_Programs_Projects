/*
To replace nth element in L by X, giving the result in L1.
*/

%base_case
repNthElem(_, _, [], _, []):-!.

%inductive_case
repNthElem(1, X, [X|T], Y, [Y|T]):-  !.
repNthElem(N, X, [X|T], Y, [X|T1]):- N1 is N-1,
				     repNthElem(N1,X,T,Y,T1),
				     !.
repNthElem(N, X, [H|T], Y, [H|T1]):- N1 is N-1,
				     repNthElem(N1,X,T,Y,T1).

/* OUTPUT
 ?- repNthElem(3, 5, [1,2,5,3,6,7], 4, L).
L = [1, 2, 4, 3, 6, 7].
*/				     
