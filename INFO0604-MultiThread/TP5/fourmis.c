
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <ncurses.h>

#define NB_LIGNES_SIM		40				/* Dimensions des fenetres du programme */
#define NB_COL_SIM			80
#define NB_LIGNES_MSG		29
#define NB_COL_MSG			49
#define NB_LIGNES_OUTILS	9
#define NB_COL_OUTILS		49

#define VIDE				0				/* Identifiants des elements pouvant etre */
#define OBSTACLE			1				/* places sur la grille de simulation */
#define FOURMI				2

typedef struct case_tag {					/* Description d'une case sur la grille de simulation */
	int element;							/* Ce qui est present sur la case */
	pthread_t *fourmi;						/* Identifiant du thread de la fourmi presente sur la case */
	pthread_mutex_t mutex;					/* Protection de la case */
} case_t;

typedef struct coord_tag {					/* Coordonnees d'une case sur la grille de simulation*/
	int y;
	int x;
} coord_t;

WINDOW *fen_sim;							/* Fenetre de simulation partagee par les fourmis*/
WINDOW *fen_msg;							/* Fenetre de messages partagee par les fourmis*/

case_t grille[NB_LIGNES_SIM][NB_COL_SIM];	/* Grille de simulation */
int nb_fourmis;								/* Nombre de fourmis de la simulation*/
pthread_mutex_t mutex_nb_fourmis;

pthread_mutex_t mutex_affichage;			/* Protection de l'affichage */

int speed = 100000;							/* Vitesse de la simulation */
pthread_mutex_t mutex_speed;				/* Protection de la vitesse de la simulation */

void ncurses_initialiser() {
	initscr();								/* Demarre le mode ncurses */
	cbreak();								/* Pour les saisies clavier (desac. mise en buffer) */
	noecho();								/* Desactive l'affichage des caracteres saisis */
	keypad(stdscr, TRUE);					/* Active les touches specifiques */
	refresh();								/* Met a jour l'affichage */
	curs_set(FALSE);						/* Masque le curseur */
	mousemask(BUTTON1_CLICKED, NULL);		/* Active le clic gauche de la souris*/
}

void ncurses_stopper() {
	endwin();
}

void simulation_initialiser() {
	int i, j;
	
	nb_fourmis = 0;							/* Au depart il n'y a aucune fourmi dans la simulation */
	pthread_mutex_init(&mutex_nb_fourmis, NULL);
	pthread_mutex_init(&mutex_affichage, NULL);

	for (i = 0; i < NB_LIGNES_SIM; i++) {	/* Initialisation des cases de la simulation */
		for (j = 0; j < NB_COL_SIM; j++) {
			grille[i][j].element = VIDE;
			grille[i][j].fourmi = NULL;
			pthread_mutex_init(&grille[i][j].mutex, NULL);
		}
	}
}

WINDOW *creer_fenetre_box_sim() {
/*Creation de la fenetre de contour de la fenetre de simulation */

	WINDOW *fen_box_sim;
	
	fen_box_sim = newwin(NB_LIGNES_SIM + 2, NB_COL_SIM + 2, 0, 0);
	box(fen_box_sim, 0, 0);
	mvwprintw(fen_box_sim, 0, (NB_COL_SIM + 2) / 2 - 5, " SIMULATION ");	
	wrefresh(fen_box_sim);
	
	return fen_box_sim;
}

WINDOW *creer_fenetre_sim() {
/* Creation de la fenetre de simulation dans la fenetre de contour */
/* La simulation est affichee dans cette fenetre */

	WINDOW *fen_sim;
	
	fen_sim = newwin(NB_LIGNES_SIM, NB_COL_SIM, 1, 1);
	
	return fen_sim;
}

WINDOW *creer_fenetre_box_msg() {
/* Creation de la fenetre de contour de la fenetre de messages */

	WINDOW *fen_box_msg;
	
	fen_box_msg = newwin(NB_LIGNES_MSG + 2, NB_COL_MSG + 2, 0, NB_COL_SIM + 2);
	box(fen_box_msg, 0, 0);
	mvwprintw(fen_box_msg, 0, (NB_COL_MSG + 2) / 2 - 4, " MESSAGES ");
	wrefresh(fen_box_msg);
	
	return fen_box_msg;
}

WINDOW *creer_fenetre_msg() {
/* Creation de la fenetre de messages dans la fenetre de contour */
/* Les messages indicatifs des evenements de la simulation et de l'interface */
/* utilisateur sont affiches dans cete fenetre */

	WINDOW *fen_msg;
	
	fen_msg = newwin(NB_LIGNES_MSG, NB_COL_MSG, 1, NB_COL_SIM + 3);
	scrollok(fen_msg, TRUE);
	
	return fen_msg;
}

WINDOW *creer_fenetre_box_outils() {
/* Fenetre de contour de la fenetre des outils */

	WINDOW *fen_box_outils;
	
	fen_box_outils = newwin(NB_LIGNES_OUTILS + 2, NB_COL_OUTILS + 2, NB_LIGNES_MSG + 2 , NB_COL_SIM + 2);
	box(fen_box_outils, 0, 0);
	mvwprintw(fen_box_outils, 0, (NB_COL_OUTILS + 2) / 2 - 3, " OUTILS ");
	wrefresh(fen_box_outils);
	
	return fen_box_outils;
}

WINDOW *creer_fenetre_outils() {
/* Creation de la fenetre des outils a l'interieur de la fenetre de contour */
/* Les outils dans cette fenetre sont clickables, l'outil actif etant indique par un X */

	WINDOW *fen_outils;
	
	fen_outils = newwin(NB_LIGNES_OUTILS, NB_COL_OUTILS, NB_LIGNES_MSG + 3, NB_COL_SIM + 3);
	mvwprintw(fen_outils, 0, 3, "# : Obstacle\n");
	mvwprintw(fen_outils, 1, 3, "@ : Fourmi");
	mvwprintw(fen_outils, 0, 1, "X");
	wrefresh(fen_outils);
	
	return fen_outils;
}

/**
 * Fonction executee par les threads fourmis
*/
void *routine_fourmi(void *arg) {
	coord_t *c = (coord_t *) arg;
	coord_t coord = *c;
	free(c);
	int_fast8_t random;

	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	
	while (1) {		
		/* Que feront les fourmis ?!?!?! */
		{
			// On choisit une direction aléatoire
			random = rand() % 4;
			int nx, ny, ox, oy;
			nx = ox = coord.x,
			ny = oy = coord.y;

			if (random == 0)
				nx = ox + 1;
			else if (random == 1)
				nx = ox - 1;
			else if (random == 2)
				ny = oy + 1;
			else
				ny = oy - 1;

			// Si les coordonnées sont valides
			if (nx >= 0 && nx < NB_COL_SIM && ny >= 0 && ny < NB_LIGNES_SIM) {

				// On verrouille les cases
				while (pthread_mutex_trylock(&grille[ny][nx].mutex) != 0)
					usleep(100000);
				pthread_mutex_lock(&grille[oy][ox].mutex);

				// Si la case est vide
				switch (grille[ny][nx].element) {
					case VIDE:
						// On déplace la fourmi
						grille[ny][nx].element = FOURMI;
						grille[ny][nx].fourmi = grille[oy][ox].fourmi;
						grille[oy][ox].element = VIDE;
						pthread_mutex_lock(&mutex_affichage);
						mvwprintw(fen_sim, oy, ox, " ");
						mvwprintw(fen_sim, ny, nx, "@");
						wrefresh(fen_sim);
						pthread_mutex_unlock(&mutex_affichage);
						coord.x = nx;
						coord.y = ny;
						break;
					case OBSTACLE:
						// On casse l'obstacle
						grille[ny][nx].element = VIDE;
						break;
					case FOURMI:
						// On mange la fourmi (destruction du thread avec deferred)
						pthread_cancel(*grille[ny][nx].fourmi);
						grille[ny][nx].element = VIDE;
						pthread_mutex_lock(&mutex_affichage);
						mvwprintw(fen_sim, ny, nx, " ");
						wrefresh(fen_sim);
						pthread_mutex_unlock(&mutex_affichage);
						break;
				}

				// On déverrouille les cases
				pthread_mutex_unlock(&grille[ny][nx].mutex);
				pthread_mutex_unlock(&grille[oy][ox].mutex);
			}
		}
		// Sleep between
		usleep((rand() % speed) + (speed / 2));
	}
	
	return NULL;
}

/**
 * Fonction qui ajoute une fourmi a la grille de simulation
*/
void ajouter_fourmi(int y, int x) {
	/* Ajoute une fourmi a la position (y, x) de la grille de simulation */
	pthread_mutex_lock(&grille[y-1][x-1].mutex);

	// Si la case est vide, on ajoute une fourmi
	if (grille[y-1][x-1].element == VIDE) {						

		// On met a jour la grille			
		grille[y-1][x-1].element = FOURMI;
		grille[y-1][x-1].fourmi = (pthread_t *) malloc(sizeof(pthread_t));

		// On cree la fourmi
		coord_t* coord = (coord_t *) malloc(sizeof(coord_t));
		coord->y = y-1;
		coord->x = x-1;
		pthread_create(grille[y-1][x-1].fourmi, NULL, routine_fourmi, (void *) coord);

		// On met a jour l'interface
		mvwprintw(fen_sim, y-1, x-1, "@");
		wprintw(fen_msg, "Ajout d'une fourmi a la position %d %d\n", y-1, x-1);
		pthread_mutex_lock(&mutex_nb_fourmis);
		nb_fourmis++;
		wprintw(fen_msg, "Nombre de fourmis : %d\n", nb_fourmis);
		pthread_mutex_unlock(&mutex_nb_fourmis);
	}
	wrefresh(fen_sim);
	wrefresh(fen_msg);
	pthread_mutex_unlock(&grille[y-1][x-1].mutex);
}

/**
 * Fonction qui ajoute un obstacle a la grille de simulation
*/
void ajouter_obstacle(int y, int x) {
	/* Ajoute un obstacle a la position (y, x) de la grille de simulation */
	pthread_mutex_lock(&grille[y-1][x-1].mutex);
	if (grille[y-1][x-1].element == VIDE) {
		grille[y-1][x-1].element = OBSTACLE;
		mvwprintw(fen_sim, y-1, x-1, "#");
		wprintw(fen_msg, "Ajout d'un obstacle a la position %d %d\n", y-1, x-1);
	}
	wrefresh(fen_sim);
	wrefresh(fen_msg);
	pthread_mutex_unlock(&grille[y-1][x-1].mutex);
}

int main(int argc, char *argv[]) {
	WINDOW *fen_box_sim, *fen_box_msg, *fen_box_outils, *fen_outils;
	MEVENT event;
	int ch, item_actif = OBSTACLE;
	coord_t *coord;
	
	// Initialisation de la grille de simulation
	ncurses_initialiser();
	simulation_initialiser();
	
	// Creation des fenetres
	fen_box_sim = creer_fenetre_box_sim();
	fen_sim = creer_fenetre_sim();
	fen_box_msg = creer_fenetre_box_msg();
	fen_msg = creer_fenetre_msg();
	fen_box_outils = creer_fenetre_box_outils();
	fen_outils = creer_fenetre_outils();
	
	// Gestion des inputs
	mvprintw(LINES - 1, 0, "Tapez F2 pour quitter");
	wrefresh(stdscr);
	while((ch = getch()) != KEY_F(2)) {
		pthread_mutex_lock(&mutex_affichage);

		switch(ch) {
			case KEY_MOUSE :
				if (getmouse(&event) == OK) {
					wprintw(fen_msg, "Clic a la position %d %d de l'ecran\n", event.y, event.x);
					wrefresh(fen_msg);
					if (event.y == 32 && event.x >= 82 && event.x <= 98) {
						item_actif = OBSTACLE;
						mvwprintw(fen_outils, 0, 1, "X");
						mvwprintw(fen_outils, 1, 1, " ");
						wrefresh(fen_outils);
						wprintw(fen_msg, "Outil obstacle active\n");
						wrefresh(fen_msg);
					}
					else if (event.y == 33 && event.x >= 82 && event.x <= 98) {
						item_actif = FOURMI;
						mvwprintw(fen_outils, 0, 1, " ");
						mvwprintw(fen_outils, 1, 1, "X");
						wrefresh(fen_outils);
						wprintw(fen_msg, "Outil fourmi active\n");
						wrefresh(fen_msg);
					}
					else if (event.y > 0 && event.y < NB_LIGNES_SIM + 1 && event.x > 0 && event.x < NB_COL_SIM + 1) {
						
						switch (item_actif) {
							case OBSTACLE :
								ajouter_obstacle(event.y, event.x);
							break;
							case FOURMI :
								ajouter_fourmi(event.y, event.x);
							break;
						}
					}
				}
			break;
			
			case 'P':
			case 'p':
				// Apparition aléatoire de 20 fourmis
				; int_fast8_t i, y, x;
				for (i = 0; i < 20; i++) {
					do {
						y = rand() % NB_LIGNES_SIM + 1;
						x = rand() % NB_COL_SIM + 1;
					} while (grille[y - 1][x - 1].element != VIDE);
					ajouter_fourmi(y, x);
				}
			break;

			case '+':
				// Augmentation de la vitesse
				pthread_mutex_lock(&mutex_speed);
				speed = speed * 9 / 10;
				if (speed < 10) speed = 10;
				wprintw(fen_msg, "Vitesse : %d\n", speed);
				wrefresh(fen_msg);
				pthread_mutex_unlock(&mutex_speed);
			break;

			case '-':
				// Diminution de la vitesse
				pthread_mutex_lock(&mutex_speed);
				speed = speed * 11 / 10;
				wprintw(fen_msg, "Vitesse : %d\n", speed);
				wrefresh(fen_msg);
				pthread_mutex_unlock(&mutex_speed);
		}

		pthread_mutex_unlock(&mutex_affichage);
	}

	// Nettoyage
	delwin(fen_box_sim);
	delwin(fen_sim);
	delwin(fen_box_msg);
	delwin(fen_msg);
	delwin(fen_box_outils);
	delwin(fen_outils);
	ncurses_stopper();

	return 0;
}
