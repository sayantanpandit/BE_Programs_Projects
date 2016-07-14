/*To delete the first occurrence of an element from a list*/
efface(_,[],[]).
/*i.e. deleting any element from an empty list will generate empty list*/
efface(A,[A|L],L):-!.
/*this is why, it can only deletes the first occurrence of A*/
/*If A is the first element in the list delete A*/
efface(A,[B|L],[B|M]):-efface(A,L,M).
/*otherwise, If is the first element of the list check the rest of the list*/
