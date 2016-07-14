/* Some facts about parent relationships */
parent('Sam','Mark').
parent('Mark','Jim').
/* A general rule */
/*that's how we define the grandparent relationship here*/
grandparent(GRANDPARENT,CHILD) :-
parent(GRANDPARENT,PARENT),  
parent(PARENT,CHILD).
