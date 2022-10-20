
:- include('FSS.prolog').

:- discontiguous mh_produits/2.
mh_produits(kog,1) :- mh_produits(knight_of_gold,1).
mh_produits(kog2,1) :- mh_produits(knight_of_gold_2,1).
mh_produits(at,300) :- mh_produits(a-toll,300).
mh_produits(b,7) :- mh_produits(bang,7).
mh_produits(s,20) :- mh_produits(siren,20).
mh_produits(jml,1) :- mh_produits(jagd_mirage_l,1).
mh_produits(jmr,1) :- mh_produits(jagd_mirage_r,1).
mh_produits(cmf,50) :- mh_produits(cross_mirage_femelle,50).
mh_produits(cmm,50) :- mh_produits(cross_mirage_male,50).


