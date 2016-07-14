member(X,[X|_]):-!.
member(X,[_|Rest]):-member(X,Rest).
intersection([],L,[]).
/*intersection of an empty set ans another set L is an empty set*/
intersection([X|L1],L2,[X|L3]):-member(X,L2),!,intersection(L1,L2,L3).
/*If X (the head element of the first set) is also a member of the second set then add X in the resultant set and continue*/
intersection([X|L1],L2,L3):-intersection(L1,L2,L3).
/*If X is only part of the first set, then discard it and continue*/
/*
Checking:
?- intersection([],[],L).
L = [].

?- intersection([a],[],L).
L = [].

?- intersection([a],[a],L).
L = [a].

?- intersection([a,b],[a],L).
L = [a].

?- intersection([a,b],[a,b,c],L).
L = [a, b].
*/
