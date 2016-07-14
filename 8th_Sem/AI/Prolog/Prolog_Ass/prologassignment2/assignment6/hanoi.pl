/*remember,in case of tower of Hanoi game, initially, all the discs are in the left pole*/
/*we have to arrange it in the middle pole according to the their increasing radius. (direction:-top to bottom)*/
/*only the top disc can be moved from one pole to another pole,and no disc may be placed on top of a smaller disc*/
/*we can use the right pole as a spare pole*/
hanoi(N):-move(N,left,centre,right).
move(0,_,_,_):-!.
/*Let us consider A as left pole, B as middle pole, C as right pole*/
/*now, to move N discs from A to B, we have to move N-1 discs from A to C using B as a spare pole, then C to B using A as a spare pole*/
move(N,A,B,C):- M is N-1, move(M,A,C,B), inform(A,B), move(M,C,B,A).
/*inform(X,Y):-  write('Move top disk from '), 
    	       write(X), 
    	       write(' to '), 
               write(Y), 
               nl.*/
inform(X,Y):-write([move,top,disk,from,pole,X,to,pole,Y]),nl.
/*nl:-to add a newline character at the end*/

/*Checking:
?- hanoi(1).
[move,top,disk,from,pole,left,to,pole,centre]
true.

?- hanoi(2).
[move,top,disk,from,pole,left,to,pole,right]
[move,top,disk,from,pole,left,to,pole,centre]
[move,top,disk,from,pole,right,to,pole,centre]
true.

?- hanoi(3).
[move,top,disk,from,pole,left,to,pole,centre]
[move,top,disk,from,pole,left,to,pole,right]
[move,top,disk,from,pole,centre,to,pole,right]
[move,top,disk,from,pole,left,to,pole,centre]
[move,top,disk,from,pole,right,to,pole,left]
[move,top,disk,from,pole,right,to,pole,centre]
[move,top,disk,from,pole,left,to,pole,centre]
true.
*/

