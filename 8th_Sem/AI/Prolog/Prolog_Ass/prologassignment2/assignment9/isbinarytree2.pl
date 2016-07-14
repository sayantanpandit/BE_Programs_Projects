binary_tree(nil).
binary_tree(t(Left,Root,Right)) :- binary_tree(Left), binary_tree(Right).
/*checking:- 
?- binary_tree(t(t(nil,a,nil),b,t(nil,c,nil))).
true.
?- binary_tree(t(t(t(nil,d,nil),a,nil),b,t(nil,c,nil))).
true.
?- binary_tree(t(t(t(nil,d,nil),a,nil),b,t(nil,c))).
false.
The  right subtree of root has only one child, so, the last case generates the answer false
*/
