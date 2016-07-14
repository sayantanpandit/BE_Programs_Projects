our_member(X,[X|_]):-!.
our_member(X,[_|Y]):-our_member(X,Y).
difference([],L,[]).
difference([X|L1],L2,L3):-our_member(X,L2),!,difference(L1,L2,L3).
difference([X|L1],L2,[X|L3]):-difference(L1,L2,L3).
