<?php

include "autoload.php";

$etudiant = new Etudiant("Jean", "Paul", 1, "Etab 1", "Licence 3");

echo "json encode :\n";
var_dump(json_encode($etudiant));

echo "json decode :\n";
var_dump(json_decode(json_encode($etudiant)));

