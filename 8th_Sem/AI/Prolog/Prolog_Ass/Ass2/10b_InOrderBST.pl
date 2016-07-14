/*
WAPP to implement Inorder traversals of Binary Search Tree.
*/

/*CODE for Inorder*/
%base_case
inorder(nil,[]).
%induction_base
inorder(t(Left,Root,Right),L):- inorder(Left,  LL),
				inorder(Right, RL),
				append(LL, [Root|RL],L).


/*CODE for Append*/
append([], X, X).
append([X|L1], L2, [X|L3]):- append(L1,L2,L3).

