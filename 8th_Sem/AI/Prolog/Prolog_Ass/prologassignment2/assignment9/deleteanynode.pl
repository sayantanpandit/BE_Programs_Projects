delete_key(Key,nil,nil):-write(Key),write(' is not in tree'),nl,!.
/*it means if we enter a key, which can not be found, if the tree is a proper bst or if the tree does not contain any value, it will not generate any new tree 
It will simply print key is not in the tree then new line (nl) 
why a cut here, because, a particular value can only be present in(at) a particular location in bst
remember, its a bst, not a normal binary tree*/
delete_key(Key,t(Key,L,nil),L):-!.
/*When Key is root value and root has only left child.
After deleting the Root(Key) Left subtree will become the new tree*/ 
/*this clause also covers for leaf when (L=nil)*/
/*Note that, here tree is in the form t(Root,Left,Right)
So, that's how it covers a leaf node when Left child is also nil with right child*/
delete_key(Key,t(Key,nil,R),R):-!.
/*similarly,when Key is Root value and it has only right child.
After deleting the Root(Key) Right subtreee will become the new tree*/
/*Now, here comes the toughest case, when Key is Root value, and Root has both right and left children.
We can do three things if the following case occurred
We can find the predecessor element of the Key(If we traverse the bst in in order and store the values in a list, then predecessor will appear just before the key in that list) and replace the key with it and delete the predecessor element from the tree
Or, we can find the successor element of the key andd replace the key with it and the delete the successor element from the tree
Or, We can hang the left subtree in the left part of right sub tree*/ 
/*Here, we go with the first choice
Now, to find the predecessor element of the Key we have to find the maximum value of it's left subtree*/
delete_key(Key, t(Key, L, R), t(Pred, NL, R)):-!, get_pred(L, Pred, NL).
delete_key(Key, t(K, L, R), t(K, NL, R)):-Key<K, !, delete_key(Key, L, NL).
delete_key(Key, t(K, L, R), t(K, L, NR)):- delete_key(Key, R, NR).
get_pred(t(Pred, L, nil), Pred, L):-!.
get_pred(t(Key, L, R), Pred, t(Key, L, NR)):-get_pred(R, Pred, NR).

/*
testing:-
?- delete_key(12,t(10,t(5,t(4,3,nil),t(6,nil,8)),t(12,t(11,nil,nil),t(13,nil,nil))),L).
L = t(10, t(5, t(4, 3, nil), t(6, nil, 8)), t(11, nil, t(13, nil, nil))).
?- delete_key(27,t(10,t(5,t(4,3,nil),t(6,nil,8)),t(12,t(11,nil,nil),t(13,nil,nil))),L).
27 is not in tree
L = t(10, t(5, t(4, 3, nil), t(6, nil, 8)), t(12, t(11, nil, nil), t(13, nil, nil))).
*/
