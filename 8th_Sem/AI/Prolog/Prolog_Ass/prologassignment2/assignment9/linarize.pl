/*We simply did inorder traversal here and add the elements into a list*/
/*inorder traversal:-Left Root Right*/
/*Extra program I guess*/
linearize(nil,[]).
linearize(t(Left,Root,Right),L):-linearlize(Left,LL),linearlize(Right,RL),append(LL,[Root|RL],L).
/*Where LL:-is the list generated by traversing the left subtree
and RL:-is the list generated by traversing the right subtree*/
append([],X,X).
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).
