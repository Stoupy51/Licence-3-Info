
:- include('FSS.prolog').

chevalier_mirage_feminin(X) :-
    chevalier_mirage(X),
    femelle(X).

role_important(X) :-
    empereur(X);
    roi(X);
    reine(X);
    prince(X);
    princesse(X).

% ou :
% role_important(X) :- empereur(X).
% role_important(X) :- roi(X).
% role_important(X) :- reine(X).
% role_important(X) :- prince(X).
% role_important(X) :- princesse(X).
% Si un plante, les autres non en soit.



% 1) Tous les faits basés sur les noms complets
% des MHs marchent aussi avec les noms abrégés.

:- discontiguous mh_produits/2.
mh_produits_2(X,Y) :- mh_produits(X,Y).
mh_produits_2(X,Y) :- mh_abrege(Z,X), mh_produits(Z,Y).




% 2) details_systeme permet de donner le détail
% de la constitution d'un système solaire donné.

details_systeme(X) :-
    systeme_solaire(X),
    format("Système solaire : ~a",[X]), nl.
details_systeme(X) :-
    soleil(Y,X),
    format("~a est un soleil de ~a",[Y,X]), nl.
details_systeme(X) :-
    planete_morte(Y,X),
    % write(Y),
    % write(" est une planète morte de "),
    % write(X),
    % nl.
    format("~a est une planète morte de ~a",[Y,X]), nl.
details_systeme(X) :-
    planete_habitee(Y,X),
    format("~a est une planète habitée de ~a",[Y,X]), nl.
details_systeme(X) :-
    asteroide(Y,X),
    format("~a est un astéroïde de ~a",[Y,X]), nl.

% findall(_,details_systeme(stant),L).



% 3) A partir d'un MH, retrouvez, si c'est
% possible, la planète à laquelle il appartient.

planete_mh(X,P) :-
    mh_principal(P,_,X,_),
    format("~a est sur la planète ~a",[X,P]), nl.



% 4) Savoir compter le nombre de chevalier
% mirage de chaque aile sans les numéros manquants

chevalier_par_aile(X) :-
    aile_droite(_,X),
    X \== inconnu.

chevalier_par_aile(X) :-
    aile_gauche(_,X),
    X \== inconnu.

chevalier_total(N) :- 
    findall(X,chevalier_par_aile(X),L),
    length(L,N).

nb_ch_mir() :-
    chevalier_total(N),
    format("Nombre de chevalier mirage de : ~a",[N]), nl.


% 5) Trouver comment faire la somme des effectifs d'une planète donnée.
//TODO


