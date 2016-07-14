/*inorder traversal:-Left Root Right*/
inorder(nil,[]).
inorder(t(Left,Root,Right),L):-inorder(Left,LL),inorder(Right,RL),append(LL,[Root|RL],L).
append([],X,X).
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).
/*
Checking:-
?- inorder(t(nil,10,t(nil,15,nil)),L).
L = [10, 15].

?- inorder(t(t(nil,5,nil),10,t(nil,15,nil)),L).
L = [5, 10, 15].
*/
