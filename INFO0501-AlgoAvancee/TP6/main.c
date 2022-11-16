
#include "table_hachage.h"
#include "time.h"

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\nDébut du main()");

	char* buffer = (char*)malloc(sizeof(char) * WORDLENGTH);
	char* files[] = {"texte1.txt", "texte2.txt", "dico_france-quebec.txt", "histoire_quebec.txt", "dico_ae.txt", "dico.txt"};
	Liste words;
	TableHachage table;
	clock_t begin;
	FILE* file;
	int i;
	unsigned long t;
	float s;

#define DoListe 0
#define DoTableHachage 1

	for (i = 0; i < 6; i++) {
		fprintf(stderr, "\n\nFichier : %s", files[i]);

#if DoListe == 1

		begin = clock();
		file = fopen(files[i], "r");
		words = initListe();
		if (file) {
			// Scan des tous les mots du fichier
			while (!feof(file)) {
				// Scan du prochain mot
				fscanf(file, "%s", buffer);

				// Liste Chainée
				if (searchInListe(words, buffer) == NULL)
					insertListe(&words, newCellule(buffer));
			}
		}

		// Liste Chainée : affichage + nettoyage
		//fprintf(stderr, "Taille de : %d mots de la ListeChainee", words.size);
		//printListe(words);
		destroyListe(&words);

		// Temps d'exécution
    	t = (clock() -  begin) * 10000 / CLOCKS_PER_SEC;
		s = t * 0.0001;
		fprintf(stderr, "\nTemps d'execution de la Liste Chainee : %.3f secondes", s);

#endif
#if DoTableHachage == 1

		begin = clock();
		file = fopen(files[i], "r");
		table = initTableHachage(11);
		if (file) {
			// Scan des tous les mots du fichier
			while (!feof(file)) {
				// Scan du prochain mot
				fscanf(file, "%s", buffer);

				// Table de Hachage
				if (searchInTableHachage(table, buffer) == NULL)
					insertTableHachage(&table, newCellule(buffer));
			}
		}

		// Table de Hachage : affichage + nettoyage
		//fprintf(stderr, "\nTaille de : %d mots de la TableHachage", wordsInTableHachage(table));
		//printTableHachage(table);
		destroyTableHachage(&table);

		// Temps d'exécution
    	t = (clock() -  begin) * 10000 / CLOCKS_PER_SEC;
		s = t * 0.0001;
		fprintf(stderr, "\nTemps d'execution de la Table de Hachage : %.3f secondes", s);

#endif
	}

	fprintf(stderr,"\n\nstringToLongLong(\"Abc\") == %lld", stringToLongLong("Abc"));

	fprintf(stderr,"\n\nFin du main()\n");	
	return 0;
}

