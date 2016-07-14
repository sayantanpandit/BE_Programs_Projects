/* To find the sum of a list of number. */

%base_case
sum([], 0).

%inductive_case
sum([H|T], Ans):- sum(T, SumTail),
		  Ans is H + SumTail.
		  
/*
?- sum([1,2,3], ANs).
ANs = 6.

?- sum([1,2,3, -6], ANs).
ANs = 0.
*/
