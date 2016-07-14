split([],[],[]).
split([A],[A],[]).
split([A,B|T],[A|P1],[B|P2]) :-
 split(T,P1,P2).
mergeSort([],[]).
mergeSort([A],[A]).
mergeSort(L1,L2) :-
 split(L1,P1,P2),
 mergeSort(P1,S1),
mergeSort(P2,S2),
merge(S1,S2,L2).
