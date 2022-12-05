
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

fiboI2(N,R) :- fiboI2(N,0,1,R).
fiboI2(1,_,R,R).
fiboI2(N,U,V,R) :- N > 1, W is U + V, N1 is N-1, fiboI2(N1,V,W,R).


% Jeu de Pièces
afficheP(P1,P2,P3) :- format("~a ~a ~a~n",[P1,P2,P3]).
retourne(pile,face).
retourne(face,pile).
iteration(P1,P2,P3,Q1,Q2,P3) :- retourne(P1,Q1), retourne(P2,Q2).
iteration(P1,P2,P3,Q1,P2,Q3) :- retourne(P1,Q1), retourne(P3,Q3).
iteration(P1,P2,P3,P1,Q2,Q3) :- retourne(P2,Q2), retourne(P3,Q3).
jeuDePieces(P1,P2,P3,R,R,R) :-
    iteration(P1,P2,P3,Q1,Q2,Q3),
    iteration(Q1,Q2,Q3,S1,S2,S3),
    iteration(S1,S2,S3,R,R,R),
    afficheP(P1,P2,P3),
    afficheP(Q1,Q2,Q3),
    afficheP(S1,S2,S3),
    afficheP(R,R,R).


% Hanoi
hanoi(0,_,_,_).
hanoi(N,D,A,T) :-
    N > 0, N1 is N-1,
    hanoi(N1,D,T,A),
    format("~a vers ~a~n",[D,A]),
    hanoi(N1,T,A,D).
hanoi(N) :- hanoi(N,'A','C','B').

    

% Les listes :

affiche([]).
affiche([X|L]) :-
    format("~a ",[X]),
    affiche(L).

afficheR([]).
afficheR([X|L]) :-
    afficheR(L),
    format("~a ",[X]).

afficheListP([]).
afficheListP([_]).
afficheListP([_,Y|L]) :-
    format("~a ",[Y]),
    afficheListP(L).

afficheListI([]).
afficheListI([X]) :- format("~a~n",[X]).
afficheListI([X,_|L]) :-
    format("~a ",[X]),
    afficheListI(L).

compte([],0).
compte([_|L],T) :- compte(L,TSL), T is TSL+1.

%compte2(L,)

somme([],0).
somme([X|L],T) :- somme(L,TSL), number(X), T is TSL+X.

sommeD(L,S) :- sommeD(L,0,S).
sommeD([],Acc,Acc).
sommeD([X|L],Acc,S) :- Acc1 is Acc+X, sommeD(L,Acc1,S).

somme2D(L,S) :- somme2D(L,0,S).
somme2D([],S,S).
somme2D([X|L],Acc,S) :- number(X), Acc1 is Acc+X, somme2D(L,Acc1,S).
somme2D([X|L],Acc,S) :- \+number(X), somme2D(L,Acc,S).

appartient(X,[X|_]).
appartient(X,[_|L]) :- appartient(X,L).

minimum([X|L],M) :- minimum(L,X,M).
minimum([],M,M).
minimum([X|L],MC,M) :- X =< MC, minimum(L,X,M).
minimum([X|L],MC,M) :- X > MC, minimum(L,MC,M).

miniR([X],X).
miniR([X|L],X) :- miniR(L,M), X =< M.
miniR([X|L],M) :- miniR(L,M), X > M.

concatener([],L,L).
concatener([X|L1],L2,[X|L3]) :- concatener(L1,L2,L3).

concatTrie([],L,L).
concatTrie(L,[],L).
concatTrie([X|L1],[Y|L2],[X|L3]) :- X < Y, concatTrie(L1,[Y|L2],L3).
concatTrie([X|L1],[Y|L2],[Y|L3]) :- X >= Y, concatTrie([X|L1],L2,L3).


