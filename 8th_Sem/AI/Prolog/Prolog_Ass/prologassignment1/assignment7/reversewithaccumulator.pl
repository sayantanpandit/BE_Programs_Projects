myreverse(L1,L2):-reverseacc(L1,[],L2).
reverseacc([],L,L).
/*in case where reverse of an empty list is needed, the result is the accumulated content so far*/
/*It it useeful, when recursively we end the last step too*/
reverseacc([X|L],L2,L3):-reverseacc(L,[X|L2],L3).
/*consider reverse([m,a,d,a,s,s],L).
reverseacc([a,d,a,s,s],[m],L3).
reverseacc([d,a,s,s],[a,m],L3).
reverseac([a,s,s],[a,m],L3).
and so on*/

