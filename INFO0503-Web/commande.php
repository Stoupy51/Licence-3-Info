<?php include "autoload.php";

// Type de document renvoyé : JSON
header("Content-Type: application/json");

if (
	isset($_POST["energyType"]) && isset($_POST["quantity"]) && isset($_POST["minQuantity"]) && isset($_POST["extractMode"]) && isset($_POST["extractModeStrict"]) && isset($_POST["energyFromCountry"]) && isset($_POST["maxPrice"]) && isset($_POST["maxBudget"])
	&& is_numeric($_POST["energyType"]) && is_numeric($_POST["quantity"]) && is_numeric($_POST["minQuantity"]) && is_numeric($_POST["extractMode"]) && is_bool($_POST["extractModeStrict"]) && is_string($_POST["energyFromCountry"]) && is_numeric($_POST["maxPrice"]) && is_numeric($_POST["maxBudget"])
) {
	if ($_POST["extractModeStrict"] == "on") {
		$extractModeStrict = true;
	}
	else {
		$extractModeStrict = false;
	}
	$commande = new Commande(0, $_POST["energyType"], $_POST["quantity"], $_POST["minQuantity"], $_POST["extractMode"], $extractModeStrict, $_POST["energyFromCountry"], 0, 0);
	echo json_encode($commande);
}
else {
	$msg = "Erreur : tous les champs n'ont pas été remplis.";
	header("Location: index.php?debug=$msg");
}

