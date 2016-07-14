member(X,[X|_]):-!.
member(X,[_|Rest]):-member(X,Rest).
union([],L,L).
/*this tells that if first set does not contain any element and second set is L then the union result will be L*/
union([X|L1],L2,L3):-member(X,L2),!,union(L1,L2,L3).
/*this tells that if X is present as the head element of the first set then we check if X is also present is the second set or not. If X is present in the second set, then do not add X from the first set (counting on the second set to add X which is common to both the set) and construct the rest of the resultant set L3 by finding union of tail set L1 of first set and L2: the second set*/
union([X|L1],L2,[X|L3]):-union(L1,L2,L3).
/*If X is only present in the first list and does not present in the second list, then add X in the resultant list*/
/*
?- union([],[1],L).
L = [1].

?- union([1],[1],L).
L = [1].

?- union([1],[1,2],L).
L = [1, 2].

?- union([1,3],[1,2],L).
L = [3, 1, 2].
*/
