/*our member function*/
our_member(X,[X|_]):-!.
our_member(X,[_|Y]):-our_member(X,Y).
/*our member function ends*/
intersection([],L,[]).
intersection([X|L1],L2,[X|L3]):-our_member(X,L2),!,intersection(L1,L2,L3).
intersection([X|L1],L2,L3):-intersection(L1,L2,L3).

