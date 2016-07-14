member(X,[X|Rest]):-!.
member(X,[Y|Rest]):-member(X,Rest).
remove_duplicates([],[]).       
remove_duplicates([H|T],X) :-member(H,T),!,remove_duplicates(T,X).
/*that means if H is already a member of tail list then  delete the firsst element and continue */
remove_duplicates([H|T],[H|X]) :- remove_duplicates(T,X).
/*otherwise, search the list for finding possible duplicates*/
