<?php include "autoload.php";

if (
	isset($_POST["energyType"]) && isset($_POST["quantity"]) && isset($_POST["minQuantity"]) && isset($_POST["extractMode"]) && isset($_POST["energyFromCountry"]) && isset($_POST["maxPrice"]) && isset($_POST["maxBudget"])
	&& is_numeric($_POST["energyType"]) && is_numeric($_POST["quantity"]) && is_numeric($_POST["minQuantity"]) && is_numeric($_POST["extractMode"]) && is_string($_POST["energyFromCountry"]) && is_numeric($_POST["maxPrice"]) && is_numeric($_POST["maxBudget"])
) {
	$commande = new Commande(
		rand(0, 2147483647),
		$_POST["energyType"],
		$_POST["quantity"],
		$_POST["minQuantity"],
		$_POST["extractMode"],
		isset($_POST["extractModeStrict"]),
		$_POST["energyFromCountry"],
		$_POST["maxPrice"],
		$_POST["maxBudget"],
		time()
	);
	$commandeJSON = json_encode($commande);

	// Envoie de la commande au TARE
	// Préparation de la requête
	$options = [
		'http' => [
			'method'  => 'POST',
			'header'  => 'Content-type: application/x-www-form-urlencoded',
			'content' => $commandeJSON
		]
	];
	// Envoi de la requête au TARE
	$file = file_get_contents("../config.json");
	$config = json_decode($file, true);
	$URL = "http://localhost:" . $config["portServeurHTTP"] . "/";
	$contexte  = stream_context_create($options);
	
	if(($jsonTexte = @file_get_contents($URL, false, $contexte)) !== false) {
		// Analyse du JSON reçu
		$tableau = json_decode($jsonTexte, true);
		if($tableau['code'] == "OK")
			echo "<p>Commande acceptée</p>";
		else
			echo "<p>Commande refusée : ". $tableau['message']."</p>";
	}
	else
		echo "<p>Une erreur est survenue lors de la récupération des données.</p>";
}
else {
	$msg = "Erreur : tous les champs n'ont pas été remplis.";
	header("Location: index.php?debug=$msg");
}

