member(X,[X|_]):-!.
member(X,[_|Rest]):-member(X,Rest).
append([],L,L).
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).
difference([],L,[]).
difference([X|L1],L2,L3):-member(X,L2),!,difference(L1,L2,L3).
difference([X|L1],L2,[X|L3]):-difference(L1,L2,L3).
symmetricdifference([],[],[]):-!.
symmetricdifference(L1,L2,L3):-difference(L1,L2,Result1),difference(L2,L1,Result2),append(Result1,Result2,L3).
/*
?- symmetricdifference([1],[],L).
L = [1].

?- symmetricdifference([1],[2],L).
L = [1, 2].

?- symmetricdifference([1,2],[2,3],L).
L = [1, 3].
*/
