/*To substitute all occurrences of one element by another element in a list*/
substitute(_,[],_,[]).
/*A:original element L:Original list B:Replace A with B M:final list*/
substitute(A,[A|L],B,[B|M]):-!,substitute(A,L,B,M).
substitute(A,[X|L],B,[X|M]):-substitute(A,L,B,M).
