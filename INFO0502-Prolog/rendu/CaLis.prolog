
% Exercice 3

% 1)
impair(X) :- X mod 2 =\= 0.

afficheNombresImpairs(N) :- N > 0, \+impair(N), N2 is N-1, afficheNombresImpairs(N2).
afficheNombresImpairs(N) :- N > 0, impair(N), N2 is N-2, afficheNombresImpairs(N2).
afficheNombresImpairs(N) :- N > 0, impair(N), format("~a ", [N]).


% 2)
estTexte(N, [_|L]) :- N > 1, N2 is N-1, estTexte(N2, L).
estTexte(1, [X|_]) :- string(X).
% 3ème élément : estTexte(3, [ 01, [], "monStr", 0.5, 5, 6, 7 ]).
% true.


% 3)
truc([], []).
truc([X|L], [X|LN]) :- X mod 2 =:= 0, truc(L, LN).
truc([X|L], LN ) :- X mod 2 =\= 0, truc(L, LN).

paires([], []).
paires([X|L], [X|LN]) :- X mod 2 =:= 0, truc(L, LN).
paires([X|L], LN ) :- X mod 2 =\= 0, truc(L, LN).

% Ce prédicat permet d'obtenir une liste des nombres paires
% grâce à la première liste passé en paramètre.
% Il doit être utilisé comme cela :
% paires([1,5,4,1,36,99,7,88,1], L).
% résultat : L = [4, 36, 88] .


