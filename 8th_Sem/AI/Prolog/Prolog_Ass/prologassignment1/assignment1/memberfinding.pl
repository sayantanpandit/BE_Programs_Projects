mymember(X,[X|Rest]):-!.
mymember(X,[Y|Rest]):-mymember(X,Rest).
/*test it:-
?- mymember(a,[b,a,c]).
true .

Find out a good thing here.
If the program shows  "ERROR: toplevel: Undefined procedure: mymember2 (DWIM could not correct goal)" this kind of error
then that means the program is either not compiled at all and or your query does not match any predicates. Check the number of arguments in query.
In my case, I have mistakenly compiled it using swipl s -memberfinding.pl instead of swipl -s memberfinding.pl
*/
