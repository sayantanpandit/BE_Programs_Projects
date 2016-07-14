next_to(X,Y,[X|[Y|Rest]]):-!.
next_to(X,Y,[H|Rest]):-next_to(X,Y,Rest).
/*Checking:
?- next_to(2,1,[3,2,1,4]).
true.
?- next_to(2,1,[3,4]).
false.
?- next_to(2,1,[3,4,1]).
false.
*/

