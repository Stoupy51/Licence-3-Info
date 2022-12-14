
% Exercice 2
afficheListP([]).
afficheListP([_]).
afficheListP([_, Y|L]) :- format("~a ",[Y]), afficheListP(L).

% 1)
testafficheListeP(L) :- trace, afficheListP(L), nodebug.

% 2)
% testafficheListeP([1,2,3,4,5,6,7]).
% 
% Nombre de Call : 7 calls (comme la taille de la liste)
% Nombre de Exit : 7 exits (comme la taille de la liste)
% Aucun Fail ni Redo car les règles et fait renvoient tout le temps true.


