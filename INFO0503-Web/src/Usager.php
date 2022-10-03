<?php

class Usager implements JsonSerializable {
    private string $nom;
    private string $prenom;
    private int $id;
    private string $etablissement;

    public function __construct(string $nom, string $prenom, int $id, string $etablissement) {
        $this->nom = $nom;
        $this->prenom = $prenom;
        $this->id = $id;
        $this->etablissement = $etablissement;
    }

    public function jsonSerialize(): array {
        return [
            "nom" => $this->nom,
            "prenom" => $this->prenom,
            "numero" => $this->id,
            "etablissement" => $this->etablissement
        ];
    }

    public static function fromJSON(string $json) : Usager {
        $data = json_decode($json, true);
        return new Usager($data["nom"], $data["prenom"], $data["numero"], $data["etablissement"]);      
    }

    /**public function __toString() : string {
        return $nom . " " . $prenom . " - " . $id . " - " . $etablissement;
    }**/
};

