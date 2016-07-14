binary_tree(nil):-!.
binary_tree(t(Left,Root,Right)) :- binary_tree(Left),!, binary_tree(Right).
/*The cut is like a switch, If binary_tree(Left) returns true, then the cut will allow to check if the right subtree is also a binary_tree*/
order([]):-!.
order([X]):-!.
order([X|[Y|Rest]]):-X=<Y,!,order([Y|Rest]).
in_order(nil,[]):-!.
in_order(t(Left,Root,Right),L):-in_order(Left,L1),in_order(Right,L2),append(L1,[Root|L2],L).
is_bst(nil):-!.
is_bst(T):-binary_tree(T),!,in_order(T,L),order(L).
/*The procedure is the following:-
First check, if the given bst is a binary tree
If yes, then traverse the given bst in in order and save the elements in a temporary array (Here, list)
Now, check if the temporary array is ordered or not.*/
/*
?- is_bst(t(nil,10,nil)).
true.

?- is_bst(t(t(nil,5,nil),10,nil)).
true.

?- is_bst(t(t(nil,5,nil),10,t(nil,15,nil))).
true.

?- is_bst(t(t(nil,5,nil),10,t(nil,7,nil))).
false.
*/

