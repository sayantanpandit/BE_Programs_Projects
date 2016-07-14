myappend([],L,L).
/*base case i.e. if we append L to  [] or L: the second list to []: an empty first list then we get L*/
myappend([X|L1],L2,[X|L3]):-myappend(L1,L2,L3).
/* i.e. if we want to append L2 the second list to the first list [X|L1]  then the resulting list will be [X|L3]
and that would be done by the recursive process of adding L2 at the end of L1 and resulting list will be L3*/
/*notice carefully, we recursively take one step down*/ 
