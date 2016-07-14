last([X],X):-!.
last([X|Rest],Y):-last(Rest,Y).
/*last element of the list testing
?- last([1,2,3],X).
X = 3.
?- last([1],X).
X = 1.
?- last([],X).
false.
*/
