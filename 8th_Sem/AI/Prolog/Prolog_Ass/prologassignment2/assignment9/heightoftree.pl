height(nil,0).
/*Height of an empty tree is 0*/
height(t(Left,Root,Right),H):-height(Left,LH),height(Right,RH),maximum(LH,RH,Hmax), H is Hmax+1.
maximum(X,Y,X):- X >= Y,!.
maximum(X,Y,Y).
/*
Checking:-
?- height(t(nil,10,nil),H).
H = 1.

?- height(t(t(nil,20,nil),10,nil),H).
H = 2.
*/
