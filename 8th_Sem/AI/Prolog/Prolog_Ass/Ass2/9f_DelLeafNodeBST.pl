/* Delete a leaf node from a BST. */

%start_case
delLeafBST(X,T,Nt):- insertBST(X,Nt,T).

%base_case
insertBST(X,nil,t(nil,X,nil)):-!.

insertBST(X,t(Left,Root,Right),t(Left1,Root,Right)):- X<Root,
						      !,
						      insertBST(X,Left,Left1).
						      
insertBST(X,t(Left,Root,Right),t(Left,Root,Right1)):- X>Root,
						      !,
						      insertBST(X,Right,Right1).
/*
Check:-
deleteleafbst(35,t(t(nil,10,nil),20,t(t(nil,25,nil),30,t(nil,35,nil))),L).
L = t(t(nil, 10, nil), 20, t(t(nil, 25, nil), 30, nil)).
*/
