
pgcd(X,Y,R) :- number(X), number(Y), X < Y, pgcd(Y,X,R).
pgcd(X,Y,Y) :- number(X), number(Y), Reste is X mod Y, Reste == 0.
pgcd(X,Y,R) :- number(X), number(Y), Reste is X mod Y, Reste \== 0, pgcd(Y,Reste,R).

% 8 tests :
% pgcd(X,Y,Z).
% pgcd(X,Y,5).
% pgcd(X,5,Z).
% pgcd(X,5,5).
% pgcd(10,Y,Z).
% pgcd(10,Y,5).
% pgcd(10,5,Z).
% pgcd(10,5,5).



% Fibonnaci :
:- dynamic fibo/2.
%fibo(N,R) :- number(N), N == 0, R is 0.
%fibo(N,R) :- number(N), N == 1, R is 1.
fibo(0,0).
fibo(1,1).
fibo(N,R) :-
    number(N),
    N > 1,
    X is N-1,
    fibo(X,A),
    Y is N-2,
    fibo(Y,B),
    R is A + B,
    asserta(fibo(N,R)).

% Version itérative
fiboI(N,R) :- fiboI(N,1,0,1,R).
fiboI(N,N,_,V,V).
fiboI(N,I,U,V,R) :-
    I < N,
    W is U + V,
    I1 is I + 1,
    fiboI(N,I1,V,W,R).


