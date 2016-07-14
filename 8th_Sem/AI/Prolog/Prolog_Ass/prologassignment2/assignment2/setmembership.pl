is_member(X,[X|_]):-!.
is_member(X,[_|Y]):-is_member(X,Y).
/*
?- is_member(1,[]).
false.

?- is_member(1,[1]).
true.

?- is_member(1,[2,1,3]).
true.
*/
