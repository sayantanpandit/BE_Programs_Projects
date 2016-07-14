natural_number(0).
natural_number(s(N)):-natural_number(N).
/***natural number implimentation***/


count(0,0).
count(s(N),R):-count(N,R1),R is R1+1.
lessthanequal(M,N):-count(M,Val1),count(N,Val2),Val1=<Val2.
greaterthan(M,N):-count(M,Val1),count(N,Val2),Val1>Val2.

/***greaterthan and lessthanequal implementation***/

plus(0,N,N):-natural_number(N).
plus(s(M),N,s(Z)):-plus(M,N,Z).

mytimes(0,N,0) :- natural_number(N).
mytimes(s(M),N,Z) :- mytimes(M,N,W), plus(W,N,Z).

squareroot(0,0):-!.
squareroot(M,R):-mytimes(R,R,Val1),mytimes(s(R),s(R),Val2),lessthanequal(Val1,M),greaterthan(Val2,M),!.
/*to have an integer squareroot value*/

/*checking:
?-  squareroot(s(s(s(s(0)))),s(s(0))).
true.

?- squareroot(s(s(s(0))),s(0)).
true.

?- squareroot(s(s(s(0))),s(s(0))).
false.
*/
