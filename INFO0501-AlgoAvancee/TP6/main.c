
#include "table_hachage.h"
#include "time.h"

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\nDébut du main()\n");

	char* buffer = (char*)malloc(sizeof(char) * WORDLENGTH);
	char* files[] = {"texte1.txt", "texte2.txt", "dico_france-quebec.txt", "histoire_quebec.txt", "dico_ae.txt", "dico.txt"};
	Liste words = initListe();
	clock_t begin;
	FILE* file;
	int i;
	
	for (i = 0; i < 6; i++) {
		begin = clock();
		fprintf(stderr, "\n\n\nFichier : %s\n", files[i]);
		file = fopen(files[i], "r");

		if (file) {
			// Scan des tous les mots du fichier
			while (!feof(file)) {
				// Scan du prochain mot
				fscanf(file, "%s", buffer);

				// Liste Chainée
				if (searchInListe(words, buffer) == NULL) {
					insertListe(&words, newCellule(buffer));
				}
			}
		}

		// Liste Chainée : affichage + nettoyage
		fprintf(stderr, "Taille de : %d mots", words.size);
		//printListe(words);
		destroyListe(&words);

		// Temps d'exécution
    	unsigned long t = (clock() -  begin) * 10000 / CLOCKS_PER_SEC;
		if (t > 10000) {
			float s = t * 0.0001;
			fprintf(stderr, "\nTemps d'execution : %.3f secondes", s);
		}
		else {
			float ms = t * 0.1;
			fprintf(stderr, "\nTemps d'execution : %.3fms", ms);
		}
	}

	fprintf(stderr,"\n\nstringToLongLong(\"Abc\") == %ld", stringToLongLong("Abc"));

	fprintf(stderr,"\nFin du main()\n");	
	return 0;
}

