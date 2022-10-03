<?php

class Etudiant extends Usager {
    private string $diplomeSuivi;

    public function __construct(string $nom, string $prenom, int $id, string $etablissement, string $diplomeSuivi) {
        parent::__construct($nom, $prenom, $id, $etablissement);
        $this->diplomeSuivi = $diplomeSuivi;
    }

    public function jsonSerialize() : array {
		$data = parent::jsonSerialize();
		$data["diplome"] = $this->diplomeSuivi;
        return $data;
    }

	public static function fromJSON(string $json) : Usager {
        $data = json_decode($json, true);
        return new Etudiant($data["nom"], $data["prenom"], $data["numero"], $data["etablissement"], $data["diplome"]);
    }
};

