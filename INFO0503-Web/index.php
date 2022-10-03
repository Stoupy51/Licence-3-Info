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
	<title>Document</title>
</head>
<body>
	<h1>Test</h1>
	<form action="index.php" method="post">
		<input type="text" name="nom" placeholder="Nom">
		<input type="text" name="prenom" placeholder="Prénom">
		<input type="text" name="numero" placeholder="Numéro">
		<input type="text" name="etablissement" placeholder="Etablissement">
		<input type="text" name="classe" placeholder="Classe">
		<input type="submit" value="Envoyer">
	</form>
</body>
</html>
HTML;
