/*WAPP to implement PostOrder Traversals of a Binary Tree.*/

/*CODE for PostOrder*/
%base_case
postorder(nil,[]).
%inductive_case
postorder(t(Left,Root,Right),L):- postorder(Left,LL),
				  postorder(Right,RL),
				  append(LL,RL,L1),
				  append(L1,[Root],L).
				  /*We have to make root as a list*/

/*CODE for APPEND*/				  
append([],X,X).
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).
/*
Checking:-
?- postorder(t(t(nil,5,nil),10,t(nil,15,nil)),L).
L = [5, 15, 10].
*/
