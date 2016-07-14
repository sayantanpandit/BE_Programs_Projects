next_to(X,Y,[X|[Y|Rest]]).
next_to(X,Y,[Z|Rest]):-next_to(X,Y,Rest).
/*
testing it:
?- next_to(a,b,[b,a,b,c]).
true .
?- next_to(a,b,[a,c,b]).
false.
*/
