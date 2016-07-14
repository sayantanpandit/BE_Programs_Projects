last([X],X).
last([X|Rest],Y):-last(Rest,Y).
/*last element of the list testing
?- last([a,b,c,d],Last).
Last = d.
*/
