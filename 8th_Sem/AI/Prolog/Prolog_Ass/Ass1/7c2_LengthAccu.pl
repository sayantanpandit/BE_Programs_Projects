/*
To determine the length of a list using Accumulator.
*/

%accumulator_introduced_and_introduced
lengthAcc(L, N):- lengthAcc(L, 0, N).

%base_case
lengthAcc([], A, A).

%inductive_case
lengthAcc([H|T], A, N):- A1 is A+1, 
			 lengthAcc(T, A1, N).  
			 
/* OUTPUT
?- lengthAcc([1,2,3,6,9], L).
L = 5.

?- lengthAcc([1,2,3,6,9, 8], L).
L = 6. 
*/ 
