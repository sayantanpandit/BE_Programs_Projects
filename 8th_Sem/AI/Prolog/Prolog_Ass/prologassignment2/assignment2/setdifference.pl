/*find the elements which are present in the first set but is not present in the second set*/
member(X,[X|_]):-!.
member(X,[_|Rest]):-member(X,Rest).
difference([],L,[]).
/*If first set is an empty set and second set is L, then the resultant set is L as resultant set represents the elements which are present in the first list, but not in the second list*/
difference([X|L1],L2,L3):-member(X,L2),!,difference(L1,L2,L3).
/*If X is present in the both set, then X should not be in the resultant set*/
difference([X|L1],L2,[X|L3]):-difference(L1,L2,L3).
/*If X is present in the first set and is not present in the second set, then X should not be present in the resultant set*/

/*
Check:
?- difference([],[1],L).
L = [].

?- difference([1],[],L).
L = [1].

?- difference([1],[1],L).
L = [].

?- difference([1,2,3],[1],L).
L = [2, 3].

?- difference([1,2,3],[1,4],L).
L = [2, 3].
*/
