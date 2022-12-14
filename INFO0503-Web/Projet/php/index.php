<?php include "autoload.php";

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
	<h1>Commande d'énergie sur le site du Revendeur</h1>
	<form action="commande.php" method="post">
		<label for="energyType">Type d'énergie</label>
		<select name="energyType" id="energyType" onchange="onEnergyTypeUpdate();">
			<option selected value="0">Électricité</option>
			<option value="1">Pétrole</option>
			<option value="2">Hydrogène</option>
		</select><br>
		<label for="quantity">Quantité</label>
		<input type="number" name="quantity" oninput="onQuantityUpdate();" value="1500"><label id="quantityLabel">kWh</label><br>
		<label for="minQuantity">Quantité minimale</label>
		<input type="number" name="minQuantity" value="1200" oninput="onQuantityUpdate();"><label id="minQuantityLabel">kWh</label><br>
		<label for="extractMode">Mode d'extraction</label>
		<select name="extractMode" id="extractMode">
			<option value="0">Éolien</option>
			<option value="1">Solaire</option>
			<option value="2">Hydraulique</option>
			<option value="3" selected>Nucléaire</option>
			<option value="4">Charbon</option>
		</select><br>
		<label for="extractModeStrict">Est-ce que le mode d'extraction est strict ?</label>
		<input type="checkbox" name="extractModeStrict" id="extractModeStrict" checked><br>
		<label for="energyFromCountry">Énergie provenant du pays</label>
		<select name="energyFromCountry" id="energyFromCountry">
			<option value="FR">France</option>
			<option value="AL">Allemagne</option>
			<option value="ES">Espagne</option>
			<option value="IT">Italie</option>
			<option value="EN_GB">Royaume-Uni</option>
			<option value="BE">Belgique</option>
		</select><br>
		<label for="maxPrice">Prix maximum</label>
		<input type="number" step="0.0001" name="maxPrice" value="0.05"><label id="maxPriceLabel">€/kWh</label><br>
		<label for="maxBudget">Budget maximum</label>
		<input type="number" name="maxBudget" value="4000"><label>€</label><br>
		<input type="submit" value="Envoyer">
	</form>
</body>
</html>
HTML;

