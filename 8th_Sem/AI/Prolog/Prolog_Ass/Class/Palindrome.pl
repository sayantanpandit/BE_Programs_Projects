/*
WAPP to determine whether a list is a palindrome or not
*/

palindrome(L):- reverse(L, L).

/*
To run the code :
swipl -s Palindrome.pl Reverse.pl Append2Lists.pl

?- palindrome([1,2,1]).
true.

?- palindrome([1,2,3]).
false.
*/
