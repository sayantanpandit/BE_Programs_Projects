/*
The tower of Hanoi is a game played with three poles and a set of discs. The discs are graded in diameter, and fit onto the poles by means of a hole cut through the center of each disc. 
Initially all the discs are on the left-hand pole. The object of the game is to move all the discs onto the center pole. The right-hand pole can be used as a “spare” pole, a temporary resting place for
discs. Each time a disc is moved from one pole to another, two constraints must be observed:
only the top disc on a pole can be moved, and no disc may be placed on top of a smaller one.

Write a Prolog program to implement the tower of Hanoi problem as stated above, i. e., 
given N, no of discs on the left pole, generate the moves that will ultimately transfer all N discs to thecenter pole.
*/


%start_state
hanoi(N):- move(N,left,centre,right).

%base_case
move(0,_,_,_):-!.

%inductive_case
move(N,A,B,C):- M is N-1, 
		move(M,A,C,B), 
		inform(A,B), 
		move(M,C,B,A).

inform(X, Y):- write([move,top,disk,from,pole,X,to,pole,Y]),nl.
