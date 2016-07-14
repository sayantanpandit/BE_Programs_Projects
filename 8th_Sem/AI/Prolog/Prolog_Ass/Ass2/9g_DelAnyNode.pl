delete_key(Key,nil,nil):-write(Key),write(' is not in tree'),nl,!.

delete_key(Key,t(Key,L,nil),L):-!.
delete_key(Key,t(Key,nil,R),R):-!.
delete_key(Key, t(Key, L, R), t(Pred, NL, R)):- !, 
						get_pred(L, Pred, NL).

delete_key(Key, t(K, L, R), t(K, NL, R)):- Key<K, 
					   !, 
					   delete_key(Key, L, NL).
					   
delete_key(Key, t(K, L, R), t(K, L, NR)):- delete_key(Key, R, NR).

get_pred(t(Pred, L, nil), Pred, L):-!.
get_pred(t(Key, L, R), Pred, t(Key, L, NR)):-get_pred(R, Pred, NR).

/*
testing:-
?- delete_key(12,t(10,t(5,t(4,3,nil),t(6,nil,8)),t(12,t(11,nil,nil),t(13,nil,nil))),L).
L = t(10, t(5, t(4, 3, nil), t(6, nil, 8)), t(11, nil, t(13, nil, nil))).
?- delete_key(27,t(10,t(5,t(4,3,nil),t(6,nil,8)),t(12,t(11,nil,nil),t(13,nil,nil))),L).
27 is not in tree
L = t(10, t(5, t(4, 3, nil), t(6, nil, 8)), t(12, t(11, nil, nil), t(13, nil, nil))).
*/
