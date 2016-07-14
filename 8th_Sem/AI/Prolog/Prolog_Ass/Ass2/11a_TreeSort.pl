/* TREE SORT */

%base_case
insertBST(X,nil,t(nil,X,nil)):-!.
insertBST(X,t(Left,Root,Right),t(Left1,Root,Right)):- X<Root, 
						      !,
						      insertBST(X,Left,Left1).
insertBST(X,t(Left,Root,Right),t(Left,Root,Right1)):- X>Root,
					 	      !,
					 	      insertBST(X,Right,Right1).
					 	      
linearize(nil,[]).
linearize(t(Left,Root,Right),L):-linearize(Left,L1),linearize(Right,L2),append(L1,[Root|L2],L).

append([],X,X).
append([X|L1],L2,[X|L3]):-append(L1,L2,L3).

treeSort([],[]):-!.
treeSort(L,L1):-insertTree(L,nil,T),linearize(T,L1).
/*linearize is for inorder traversal*/
/*Li stands for L intermediate*/

insertTree([],A,A):-!.
insertTree([H|Rest],A,T):- insertBST(H,A,Nt),
			   insertTree(Rest,Nt,T).

/*Checking:-
?- treesort([20,10,30],L).
L = [10, 20, 30].

?- treesort([20,10,30,50,40],L).
L = [10, 20, 30, 40, 50].
*/
