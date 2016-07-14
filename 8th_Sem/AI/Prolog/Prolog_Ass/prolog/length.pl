mylength([],0).
mylength([H|T],N+1):-mylength(T,N).
/*Testing:
?- mylength([a,b,c],Ans).
Ans = 0+1+1+1.
*/
