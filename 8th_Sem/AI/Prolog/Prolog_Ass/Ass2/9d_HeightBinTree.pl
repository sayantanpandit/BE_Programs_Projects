/* Height of a Binary Tree. */

%base_case
height(nil,0).

%inductive_case
height(t(Left,Root,Right),H):- height(Left,LH),
			       height(Right,RH),
			       maximum(LH,RH,Hmax), 
			       H is Hmax+1.
/* Maximum between Left-Right*/			       
maximum(X,Y,X):- X >= Y,!.
maximum(X,Y,Y).

/*
Checking:-
?- height(t(nil,10,nil),H).
H = 1.

?- height(t(t(nil,20,nil),10,nil),H).
H = 2.
*/
