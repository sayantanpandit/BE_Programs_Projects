is_bst(nil):-!.
is_bst(T):-bst(T,2147483647,-2147483648).
/*bst(T,INT_MAX,INT_MIN).*/
bst(nil,Max,Min):-!.
bst(t(nil,Root,nil),Max,Min):-Root<Max,Root>Min,!.
bst(t(Left,Root,Right),Max,Min):-Root<Max,Root>Min,!,Max1 is Root-1,bst(Left,Max1,Min),!,Min1 is Root+1,bst(Right,Max,Min1).
/*
?- is_bst(t(t(t(nil,1,nil),2,t(nil,4,nil)),3,t(nil,5,nil))).
false.
?- is_bst(t(t(nil,10,nil),20,t(nil,30,nil))).
true.
?- is_bst(t(t(nil,10,nil),20,t(nil,15,nil))).
false.
*/

