mysum([],0).
mysum([H|T],Sum):-mysum(T,Sumtail), Sum is H+Sumtail.
