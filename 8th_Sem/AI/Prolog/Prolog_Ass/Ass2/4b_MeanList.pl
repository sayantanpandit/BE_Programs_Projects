/* To find the mean of a list of number. */

/* SUM of a LIST */
%base_case
sum([], 0).
%inductive_case
sum([H|T], Ans):- sum(T, SumTail),
		  Ans is H + SumTail.

/* LENGTH of a LIST */		  
%base_case
lengthList([], 0).
%inductive_case
lengthList([H|T], N):- lengthList(T, N1), 
		       N is N1+1.		  
/* MEAN of a LIST */
%base_case
mean([],0):- !.
%inductive_case
mean(L,X):- sum(L,Sum), 
 	    lengthList(L,Length), 
 	    X is Sum/Length.		  

/*
?- mean([1,2,3,4], Ans).
Ans = 2.5.
*/
