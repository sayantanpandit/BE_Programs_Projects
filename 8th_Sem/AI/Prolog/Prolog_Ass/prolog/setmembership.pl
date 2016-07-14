/*To check whether an element is present in the set or not*/
is_member(X,[X|_]):-!.
/*i.e.if the member is found at the beginning of the list, return true and terminate or stop the recursion*/
is_member(X,[_|Y]):-is_member(X,Y).

