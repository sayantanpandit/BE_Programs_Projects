/*write the delete any node program with the tree as t(Left,Root,Right) form instead of t(Root,Left,Right) Form*/
delete_key(Key,nil,nil):-write(Key),write(' is not found in the tree.'),nl,!.
delete_key(Key,t(Left,Key,nil),Left):-!.
delete_key(Key,t(nil,Key,Right),Right):-!.
delete_key(Key,t(Left,Key,Right),t(LeftNew,Predecessor,Right)):-!,get_predecessor(Predecessor,Left,LeftNew).
/*get_predecessor predicate gets the predecessor element and generate a new Left subtree with the predecessor element removed*/
delete_key(Key,t(Left,Root,Right),t(LeftNew,Root,Right)):-Key<Root,!,delete_key(Key,Left,LeftNew).
/*If Key element is less than the current root value, then we have to traverse the Left subtree to delete the Key.
So, after deleting the Key from the left subtree(Left), a new Left subtree will be generated (LeftNew)*/
delete_key(Key,t(Left,Root,Right),t(Left,Root,RightNew)):-delete_key(Key,Right,RightNew).
/*Note that, in the last clause, we neither have any condition set as Key>Root not we have any cut
It's simply because, the last three clauses are mutually exclusive*/
get_predecessor(Predecessor,t(Left,Predecessor,nil),Left):-!.
get_predecessor(Predecessor,t(Left,Root,Right),t(Left,Root,RightNew)):-get_predecessor(Predecessor,Right,RightNew).
/*Note that, to find the predecessor element of the Key element we have to find the maximum value in thhe left Subtree.
So, It is basically the rightmost Node value of the left subtree*/

/*
?- delete_key(12,t(t(t(3,4,nil),5,t(nil,6,8)),10,t(t(nil,11,nil),12,t(nil,13,nil))),L).
L = t(t(t(3, 4, nil), 5, t(nil, 6, 8)), 10, t(nil, 11, t(nil, 13, nil))).
?- delete_key(5,t(t(t(3,4,nil),5,t(nil,6,8)),10,t(t(nil,11,nil),12,t(nil,13,nil))),L).
L = t(t(3, 4, t(nil, 6, 8)), 10, t(t(nil, 11, nil), 12, t(nil, 13, nil))).
?-  delete_key(27,t(t(t(3,4,nil),5,t(nil,6,8)),10,t(t(nil,11,nil),12,t(nil,13,nil))),L).
27 is not found in the tree.
L = t(t(t(3, 4, nil), 5, t(nil, 6, 8)), 10, t(t(nil, 11, nil), 12, t(nil, 13, nil))).
*/

