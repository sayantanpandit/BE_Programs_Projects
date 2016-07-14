/*
  To add an element to a list if the element  
  is not present in the list.
*/

%base_case
our_add(A, [], [A]).

%inductive_case
our_add(A, L, L):- our_member(A, L), !.

our_add(A, L, [A|L]).

/*
To run the code:
swipl -s AddElemInList.pl ElemMember.pl Append2Lists.pl 

?- our_add(5, [1,2,3,4], L).
L = [5, 1, 2, 3, 4].

?- our_add(4, [1,2,3,4], L).
L = [1, 2, 3, 4].
*/
