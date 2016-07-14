same_length([],[]).
same_length([X|Rest1],[Y|Rest2]):-same_length(Rest1,Rest2).
/*Testing:-
?- same_length([a,b,c,d],[e,f,g,h]).
true.
?- same_length([a,b,c,d],[e,f]).
false.
*/
