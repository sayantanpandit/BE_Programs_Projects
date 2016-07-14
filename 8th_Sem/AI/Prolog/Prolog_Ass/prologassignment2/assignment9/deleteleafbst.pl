insertbst(X,nil,t(nil,X,nil)):-!.
insertbst(X,t(Left,Root,Right),t(Left1,Root,Right)):-X<Root,!,insertbst(X,Left,Left1).
insertbst(X,t(Left,Root,Right),t(Left,Root,Right1)):-X>Root,!,insertbst(X,Right,Right1).
deleteleafbst(X,T,Nt):-insertbst(X,Nt,T).
/*
Check:-
deleteleafbst(35,t(t(nil,10,nil),20,t(t(nil,25,nil),30,t(nil,35,nil))),L).
L = t(t(nil, 10, nil), 20, t(t(nil, 25, nil), 30, nil)).
*/
