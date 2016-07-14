/* Insert an element in a Binary Search Tree. */

%base_case
insert_in_bst(X,nil,t(nil,X,nil)):-!.

%inductive_case
insert_in_bst(X,t(Left,Root,Right),t(Left1,Root,Right)):- X<Root, 
							  !,
							  insert_in_bst(X,Left,Left1).
							  
insert_in_bst(X,t(Left,Root,Right),t(Left,Root,Right1)):- X>Root,
							  !,
							  insert_in_bst(X,Right,Right1).

/*Checking:
- insert_in_bst(5,nil,T).
T = t(nil, 5, nil).

?- insert_in_bst(4,t(nil,5,nil),T).
T = t(t(nil, 4, nil), 5, nil).

?- insert_in_bst(10,t(t(nil, 4, nil), 5, nil),T).
T = t(t(nil, 4, nil), 5, t(nil, 10, nil)).

?- insert_in_bst(15,t(t(nil, 4, nil), 5, t(nil, 10, nil)),T).
T = t(t(nil, 4, nil), 5, t(nil, 10, t(nil, 15, nil))).
*/
