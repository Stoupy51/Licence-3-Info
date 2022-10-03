<?php

class Commande implements JsonSerializable {
    private int $energyType;
    private float $wantedQuantity;
    private float $minQuantity;
    private int $id;
    private string $etablissement;

    public function __construct() {
        $this->nom = $nom;
        $this->prenom = $prenom;
        $this->id = $id;
        $this->etablissement = $etablissement;
    }

    public function jsonSerialize(): array {
        return [
            "nom" => $this->nom,
        ];
    }

    public static function fromJSON(string $json) : Commande {
        $data = json_decode($json, true);
        return new Commande();      
    }
};

