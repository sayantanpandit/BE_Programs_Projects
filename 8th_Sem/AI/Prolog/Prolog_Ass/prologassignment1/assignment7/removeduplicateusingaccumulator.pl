member(X,[X|Rest]):-!.
member(X,[Y|Rest]):-member(X,Rest).
removedup(L,M):-removedupacc(L,[],M).
/*introducing and instantiating accumulator*/ 
removedupacc([],A,A).
/*It says that if the list is empty, the result will be whatever we have accumulated so far*/
removedupacc([H|T],A,M):-member(H,A),!,removedupacc(T,A,M).
/*It checks that if the next element of the list (the head element of the current list) is already present in the list accumulated so far, we will not add it in the final list*/
removedupacc([H|T],A,M):-removedupacc(T,[H|A],M).
/*otherwise, if the first element of the current list is not a member of the accumulated list then we will add the first element in the accumulated list*/

