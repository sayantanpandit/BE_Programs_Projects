mylength([],0).
mylength([H|T],N):-mylength(T,N1), N is N1+1.
