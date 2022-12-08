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
	private int $date;

    public function __construct(int $id, int $energyType, float $quantity, float $minQuantity, int $extractMode, bool $extractModeStrict, string $energyFromCountry, float $maxPrice, float $maxBudget, int $date = 0) {
		$this->id = $id;
		$this->energyType = $energyType;
		$this->quantity = $quantity;
		$this->minQuantity = $minQuantity;
		$this->extractMode = $extractMode;
		$this->extractModeStrict = $extractModeStrict;
		$this->energyFromCountry = $energyFromCountry;
		$this->maxPrice = $maxPrice;
		$this->maxBudget = $maxBudget;
		$this->date = $date;
	}

    public function jsonSerialize(): array {
		return [
			'id' => $this->id,
			'energyType' => $this->energyType,
			'quantity' => $this->quantity,
			'minQuantity' => $this->minQuantity,
			'extractMode' => $this->extractMode,
			'extractModeStrict' => $this->extractModeStrict,
			'energyFromCountry' => $this->energyFromCountry,
			'maxPrice' => $this->maxPrice,
			'maxBudget' => $this->maxBudget,
			'date' => $this->date,
			'fournisseur' => "null"
		];
    }

    public static function fromJSON(string $json) : Commande {
        $data = json_decode($json, true);
        return new Commande($data['id'], $data['energyType'], $data['quantity'], $data['minQuantity'], $data['extractMode'], $data['extractModeStrict'], $data['energyFromCountry'], $data['maxPrice'], $data['maxBudget'], $data['date']);
    }
};

