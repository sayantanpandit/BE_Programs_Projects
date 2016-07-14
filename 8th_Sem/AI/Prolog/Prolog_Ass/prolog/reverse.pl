myreverse([],[]).
myreverse([H|Tail],L):-
myreverse(Tail,Z),append(Z,[H],L).
/*how this is going to work:-
of course the base case is myreverse([],[]).
i.e. if we reverse an empty list it will generate an empty list
Now, consider myreverse([H|Tail],L)
i.e. a list which contains H as first element and the reverse list will be L
how will we do it
let's generate the reverse of tail list first i.e. Z is the reverse of Tail list and append the first element of the original list to the reverse list of Tail: Z*/
