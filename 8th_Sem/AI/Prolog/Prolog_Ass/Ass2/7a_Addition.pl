/*WAPP to generate the output like this : */
/*E.g : ?- plus(s( s( 0)), s(s(s(0))), X).
  Output : { X= s(s( s( s( s( 0)))))}
  that is, 2+3 = 5. */

%start_case
addition(0,N,N) :- natural_number(N).
addition(s(M),N,s(Z)) :- addition(M,N,Z).

%base_case
natural_number(0).
%inductive_case
natural_number(s(N)) :- natural_number(N).

/* OUTPUT 
addition(s(0),s(s(0)),L).
L = s(s(s(0))).
*/
