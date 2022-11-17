
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
    format("Système solaire : ~a~n",[X]).
details_systeme(X) :-
    soleil(Y,X),
    format("~a est un soleil de ~a~n",[Y,X]).
details_systeme(X) :-
    planete_morte(Y,X),
    % write(Y),
    % write(" est une planète morte de "),
    % write(X),
    % nl.
    format("~a est une planète morte de ~a~n",[Y,X]).
details_systeme(X) :-
    planete_habitee(Y,X),
    format("~a est une planète habitée de ~a~n",[Y,X]).
details_systeme(X) :-
    asteroide(Y,X),
    format("~a est un astéroïde de ~a~n",[Y,X]).

% findall(_,details_systeme(stant),L).



% 3) A partir d'un MH, retrouvez, si c'est
% possible, la planète à laquelle il appartient.

planete_mh(X,P) :-
    mh_principal(P,_,X,_),
    format("~a est sur la planète ~a~n",[X,P]).



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
    format("Nombre de chevalier mirage de : ~a~n",[N]).


% 5) Trouver comment faire la somme des effectifs d'une planète donnée.
effectifs_planete(X,N) :-
    effectifs(A,N),
    mh_principal(X,A,_,_).

sum_of_planet(X) :-
    (planete_habitee(X,_);planete_morte(X,_)),
    findall(Y,effectifs_planete(X,Y),L),
    sum_list(L,N),
    format("Effectifs de la planète ~a : ~a~n",[X,N]).


% fsspedia
fsspedia(X) :- male(X), format("~a est un male~n",[X]).
fsspedia(X) :- femelle(X), format("~a est une femelle~n",[X]).
fsspedia(X) :- empereur(X), format("~a est un empereur~n",[X]).
fsspedia(X) :- reine(X), format("~a est une reine~n",[X]).
fsspedia(X) :- roi(X), format("~a est un roi~n",[X]).
fsspedia(X) :- princesse(X), format("~a est une princesse~n",[X]).
fsspedia(X) :- prince(X), format("~a est un prince~n",[X]).
fsspedia(X) :- mh_meister(X), format("~a est un mh_meister~n",[X]).
fsspedia(X) :- fatima_might(X), format("~a est une fatima_might~n",[X]).
fsspedia(X) :- mh_might(X), format("~a est un mh_might~n",[X]).
fsspedia(X) :- est_en_vrai(X,Y), format("~a est en vrai ~a~n",[X,Y]).
fsspedia(X) :- fatima(X), format("~a est une fatima~n",[X]).
fsspedia(X) :- etlamr(X), format("~a est une etlamr~n",[X]).
fsspedia(X) :- chevalier(X), format("~a est un chevalier~n",[X]).
fsspedia(X) :- chevalier_mirage(X), format("~a est un chevalier_mirage~n",[X]).
fsspedia(X) :- aile_droite(Y,X), format("~a est dans l''aile droite ~a~n",[X,Y]).
fsspedia(X) :- aile_gauche(Y,X), format("~a est dans l''aile gauche ~a~n",[X,Y]).
fsspedia(X) :- partenaires(X,Y), format("~a est la partenaire de ~a~n",[X,Y]).
% reste flemme


% Appels récursifs
sds(X,Y) :- soleil(X,Y), X \== Y.
sds(X,Y) :- sds(X,Z), soleil(Z,Y), Z \== Y.
sds2(X,Y) :- soleil(X,Y), X \== Y.
sds2(X,Y) :- soleil(Z,Y), Z \== Y, sds2(X,Z).
% Première version non valide car l'appel récursif se fait avant la condition d'arrêt.



