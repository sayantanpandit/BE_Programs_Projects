%start_case
is_bst(nil):-!.

%inductive_case
is_bst(T):- binary_tree(T),
	    !,
	    in_order(T,L),
	    order(L).


binary_tree(nil):-!.
binary_tree(t(Left,Root,Right)) :- binary_tree(Left),
				   !, 
				   binary_tree(Right).
				   
/*The cut is like a switch, 
  If binary_tree(Left) returns true, 
  then the cut will allow to check 
  if the right subtree is also a binary_tree*/

order([]):-!.
order([X]):-!.
order([X|[Y|Rest]]):-X=<Y,!,order([Y|Rest]).

in_order(nil,[]):-!.
in_order(t(Left,Root,Right),L):- in_order(Left,L1),
				 in_order(Right,L2),
				 append(L1,[Root|L2],L).
/*EXAMPLE
?- is_bst(t(nil,10,nil)).
true.

?- is_bst(t(t(nil,5,nil),10,nil)).
true.

?- is_bst(t(t(nil,5,nil),10,t(nil,15,nil))).
true.

?- is_bst(t(t(nil,5,nil),10,t(nil,7,nil))).
false.
*/

