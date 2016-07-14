mylength([],0).
mylength([H|T],s(N)):-mylength(T,N).
/*in function s(N) s should be in small letter*/
/*?- mylength([a,b],Ans).
Ans = s(s(0)).
*/
