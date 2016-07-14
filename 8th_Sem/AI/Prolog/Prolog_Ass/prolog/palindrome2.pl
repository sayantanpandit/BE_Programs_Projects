/*writing palindrome function using myreverse function*/
myreverse([],[]).
myreverse([H|T],L):-myreverse(T,Z),append(Z,[H],L).
palindrome(L):-myreverse(L,L).

