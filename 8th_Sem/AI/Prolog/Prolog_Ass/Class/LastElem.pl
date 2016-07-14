
%base_case
last([X]):- write(X).

%inductive_case
last([X|Rest]) :- last([Rest]).

/*
last([X],X).
last([X|Rest],Y):-last(Rest,Y).
*/
