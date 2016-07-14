/* GCD of two numbers */
%base_case
gcd(X, X, X).

%inductive_case
gcd(X, Y, Z):-
             X < Y,
	     Y1 is Y-X,
	     gcd(X,Y1,Z).

gcd(X,Y,Z):-
             X>Y,
             gcd(Y,X,Z).
             
/*
OUTPUT:
?- gcd(5, 10, Ans).
Ans = 5 .

?- gcd(12, 10, Ans).
Ans = 2 .
*/             
