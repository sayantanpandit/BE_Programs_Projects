mylength([],0).
mylength([H|T],N):-N is N1+1, mylength(T,N1).
