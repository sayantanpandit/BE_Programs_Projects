gcd(X,0,X):-!.
 /* first clause not needed because of the last clause*/
gcd(0,X,X):-!.
gcd(X,X,X):-!.
gcd(X,Y,Z):-X<Y,!,Y1 is Y-X,gcd(X,Y1,Z).
gcd(X,Y,Z):-X>Y,!,gcd(Y,X,Z).

