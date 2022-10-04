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



echo <<<HTML
<!DOCTYPE html>
<html lang="fr">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>TP Web Server</title>
</head>
<body>
	<h1>Commande d'énergie</h1>
	<form action="commande.php" method="post">
		<label for="energyType">Type d'énergie</label>
		<input type="text" name="energyType" placeholder="(électricité, pétrole, hydrogène)"><br>
		<input type="submit" value="Envoyer">
	</form>
</body>
</html>
HTML;
