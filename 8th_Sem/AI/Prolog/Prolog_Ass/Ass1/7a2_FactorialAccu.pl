
%start_state
factAccu(N,Ans):- factCal(N,1,Ans).

%base_case
factCal(0,A,A).

%inductive_case
factCal(N,A,Ans):- N1 is N-1,
		   A1 is A*N,
		   factCal(N1,A1,Ans).
		   
/*
OUTPUT
?- factAccu(5, Ans).
Ans = 120 .

?- factAccu(10, Ans).
Ans = 3628800 .
*/		   
