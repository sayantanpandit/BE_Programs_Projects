innerproduct([],_,0):-!.
innerproduct(_,[],0):-!.
innerproduct([H1|T1],[H2|T2],X):-innerproduct(T1,T2,X1),X is X1+H1*H2.
/*?- 
innerproduct([1],[2],L).
L = 2.

?- innerproduct([1,3],[2],L).
L = 2.

?- innerproduct([1,3],[2,4],L).
L = 14.
*/
