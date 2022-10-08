<?php include "autoload.php";

/***
$etudiant = new Etudiant("Jean", "Paul", 1, "Etab 1", "Licence 3");

echo "json encode :<br>";
var_dump(json_encode($etudiant));

echo "<br><br>json decode :<br>";
var_dump(json_decode(json_encode($etudiant)));

echo "<br><br>Etudiant::fromJSON :<br>";
$etudiant2 = Etudiant::fromJSON(json_encode($etudiant));
var_dump(json_encode($etudiant2));
**/

$debug = "";
if (isset($_GET["debug"])) {
	$debug = $_GET["debug"];
}

echo <<<HTML
<!DOCTYPE html>
<html lang="fr">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>TP Web Server</title>
	<script src="main.js"></script>
</head>
<body>
$debug
	<h1>Commande d'énergie</h1>
	<form action="commande.php" method="post">
		<label for="energyType">Type d'énergie</label>
		<select name="energyType" id="energyType" onchange="onEnergyTypeUpdate();">
			<option value="0">Électricité</option>
			<option value="1">Pétrole</option>
			<option value="2">Hydrogène</option>
		</select><br>
		<label for="quantity">Quantité</label>
		<input type="number" name="quantity" oninput="onQuantityUpdate();"><label id="quantityLabel">kWh</label><br>
		<label for="minQuantity">Quantité minimale</label>
		<input type="number" name="minQuantity" value="1000" oninput="onQuantityUpdate();"><label id="minQuantityLabel">kWh</label><br>
		<label for="extractMode">Mode d'extraction</label>
		<select name="extractMode" id="extractMode">
			<option value="0">Éolien</option>
			<option value="1">Solaire</option>
			<option value="2">Hydraulique</option>
			<option value="3">Nucléaire</option>
			<option value="4">Charbon</option>
		</select><br>
		<label for="extractModeStrict">Est-ce que le mode d'extraction est strict ?</label>
		<input type="checkbox" name="extractModeStrict" id="extractModeStrict"><br>
		<label for="energyFromCountry">Énergie provenant du pays</label>
		<select name="energyFromCountry" id="energyFromCountry">
			<option value="FR">France</option>
			<option value="AL">Allemagne</option>
			<option value="ES">Espagne</option>
			<option value="IT">Italie</option>
			<option value="EN-GB">Royaume-Uni</option>
			<option value="BE">Belgique</option>
		</select><br>
		<label for="maxPrice">Prix maximum</label>
		<input type="number" step="0.0001" name="maxPrice"><label id="maxPriceLabel">€/kWh</label><br>
		<label for="maxBudget">Budget maximum</label>
		<input type="number" name="maxBudget"><label>€</label><br>
		<input type="submit" value="Envoyer">
	</form>
</body>
</html>
HTML;

