order([]).
/*an empty list is always ordered*/
order([X]).
/*a list containing single element is always ordered*/
order([X|[Y|Rest]]):-X<=Y,order([Y|Rest]).
/*if the head element of a list is <= the first or head element of the tail list then try to order the tail list*/
append([],L,L).
append([X|L1],L2,L3):-append(L1,L2,L3).
partition(H,[A|X],[A|Y],Z):-order(A,H),partition(H,X,Y,Z).
partition(H,[A|X],Y,[A|Z]):-+\(order(A,H)),partition(H,X,Y,Z).
partition(_,[],[],[]).
quicksort([],[]).
quicksort([H|T],S):-partition(H,T,A,B),quicksort(A,A1),quicksort(B,B1),append(A1,[H|B1],S).

