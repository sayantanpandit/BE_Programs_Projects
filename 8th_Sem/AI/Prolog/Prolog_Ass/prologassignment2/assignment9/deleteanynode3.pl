delete_key(Key,nil,nil):-write(Key),write(' is not found in the tree'),nl,!.
delete_key(Key,t(Left,Key,nil),Left):-!.
delete_key(Key,t(nil,Key,Right),Right):-!.
delete_key(Key,t(Left,Key,Right),t(Left,Successor,RightNew)):-!,get_successor(Successor,Right,RightNew).
/*The replacement is done with Successor element this time*/
delete_key(Key,t(Left,Root,Right),t(LeftNew,Root,Right)):-Key<Root,!,delete_key(Key,Left,LeftNew).
delete_key(Key,t(Left,Root,Right),t(Left,Root,RightNew)):-delete_key(Key,Right,RightNew).


getsuccessor(Successor,t(nil,Successor,Right),Right):-!.
get_predecessor(Successor,t(Left,Root,Right),t(LeftNew,Root,Right)):-get_successor(Successor,Left,LeftNew).

