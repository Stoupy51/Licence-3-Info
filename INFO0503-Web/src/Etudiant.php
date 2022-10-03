<?php

class Etudiant extends Usager {
    private string $diplomeSuivi;

    public function __construct(string $nom, string $prenom, int $id, string $etablissement, string $diplomeSuivi) {
        Parent::__construct($nom, $prenom, $id, $etablissement);
        $this->diplomeSuivi = $diplomeSuivi;
    }

    public function jsonSerialize() : array {
        return [
            "nom" => $this->nom,
            "prenom" => $this->prenom,
            "numero" => $this->id,
            "etablissement" => $this->etablissement,
            "diplomeSuivi" => $this->diplomeSuivi
        ];
    }
};

