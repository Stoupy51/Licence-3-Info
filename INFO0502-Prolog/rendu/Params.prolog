
% Exercice 1

% 1)
fourmi(oriechinatior).
fourmi(octospinosus).
fourmi(laevicepts).
fourmi(gilberti).

% 2)
combinefourmi(A, B) :- fourmi(A), fourmi(B), A @< B.


