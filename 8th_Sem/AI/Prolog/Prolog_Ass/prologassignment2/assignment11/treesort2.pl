insertbst(X,nil,t(nil,X,nil)):-!.
insertbst(X,t(Left,Root,Right),t(Left1,Root,Right)):-X<Root,!,insertbst(X,Left,Left1).
insertbst(X,t(Left,Root,Right),t(Left,Root,Right1)):-X>Root,!,insertbst(X,Right,Right1).


delete_key(Key,nil,nil):-write(Key),write(' is not found in the tree.'),nl,!.
delete_key(Key,t(Left,Key,nil),Left):-!.
delete_key(Key,t(nil,Key,Right),Right):-!.
delete_key(Key,t(Left,Key,Right),t(LeftNew,Predecessor,Right)):-!,get_predecessor(Predecessor,Left,LeftNew).
delete_key(Key,t(Left,Root,Right),t(LeftNew,Root,Right)):-Key<Root,!,delete_key(Key,Left,LeftNew).
delete_key(Key,t(Left,Root,Right),t(Left,Root,RightNew)):-delete_key(Key,Right,RightNew).

get_predecessor(Predecessor,t(Left,Predecessor,nil),Left):-!.
get_predecessor(Predecessor,t(Left,Root,Right),t(Left,Root,RightNew)):-get_predecessor(Predecessor,Right,RightNew).


find_min_bst(t(nil,Root,nil),Root):-!.
find_min_bst(t(nil,Root,Right),Root):-!.
find_min_bst(t(Left,Root,Right),Min):-find_min_bst(Left,Min).

linearize(nil,[]):-!.
linearize(T,L):-linearizeacc(T,[],L).

linearizeacc(nil,A,A):-!.
linearizeacc(T,A,Result):-find_min_bst(T,Min),append(A,[Min],A1),delete_key(Min,T,TNew),linearizeacc(TNew,A1,Result).

treesort([],[]):-!.
treesort(L,L1):-inserttree(L,nil,T),linearize(T,L1).

inserttree([],A,A):-!.
inserttree([H|Rest],A,T):-insertbst(H,A,Nt),inserttree(Rest,Nt,T).

append([],X,X).
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).


/*Procedure:-
As described in the problem statement*/

/*Checking:-
?- treesort([],L).
L = [].

?- treesort([20],L).
L = [20].

?- treesort([20,10],L).
L = [10, 20].

?- treesort([20,10,30],L).
L = [10, 20, 30].

?- treesort([20,10,40,30],L).
L = [10, 20, 30, 40].

?- treesort([20,10,40,30,50],L).
L = [10, 20, 30, 40, 50].
*/
