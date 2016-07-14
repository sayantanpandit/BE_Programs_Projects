/*inorder traversal:-Root Left Right*/

/*CODE for PreOrder*/
%base_case
preorder(nil,[]).
%inductive_case
preorder(t(Left,Root,Right),L):- preorder(Left, LL),
				 preorder(Right,RL),
				 append([Root|LL],RL,L).
/*CODE for Append*/	
%base_case			 
append([],X,X).
%inductive_case
append([X|L1],L2,[X|L3]):- append(L1,L2,L3).

/*Checking:
?- preorder(t(nil,10,t(nil,15,nil)),L).
L = [10, 15].

?- preorder(t(t(nil,5,nil),10,t(nil,15,nil)),L).
L = [10, 5, 15].
*/
