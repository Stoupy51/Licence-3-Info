<?php

class Commande implements JsonSerializable {
	private int $id;
    private int $energyType;
    private float $quantity;
    private float $minQuantity;
    private int $extractMode;
	private bool $extractModeStrict;
	private string $energyFromCountry;
    private float $maxPrice;
	private float $maxBudget;

    public function __construct(int $id, int $energyType, float $quantity, float $minQuantity) {
		;
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

