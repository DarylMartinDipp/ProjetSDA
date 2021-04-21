/**
 * @file sprint6.cpp
 * @brief Lire un plateau suivi d'une liste de mots saisis au clavier
 * et afficher � l'�cran les mots de la liste �tant pr�sents sur la plateau.
 */

#include <iostream>
#include <cassert>
#include "sprint2.h"
#include "sprint6.h"

using namespace std;

ConteneurTDE c7;
Grille gr;
Adjacent adj;
Visite vst;

void constructGrille() {
	// initialise la variable mot de type Mot � 0
	Mot mot;
	// Initialisation de la variable j � 0, un unsigned int car il ne va jamais �tre n�gatif.
	// Cette variable correspond au rang auquel va �tre plac� chaque lettre des 4 mots entr�s,
	// dans la structure Grille.
	unsigned int j = 0;

	// Boucle permettant de prendre les 4 premiers mots entr�s � l'�cran, gr�ce au i, un unsigned
	// int variant de 0 � 3.
	for (unsigned int i = 0; i < 4; i++) {
		// entr�e du mot � l'�cran
		cin >> mot;
		// Boucle permettant de parcourir chaque lettre de chaque mot.
		// Comme il y a 4 lettres dans les mots, le k varie de 0 � 3.
		for (unsigned int k = 0; k < 4; k++) {
			// permet de rentrer la lettre du mot � la position k dans la grille � la position j
			gr.grille[j] = mot[k];
			// incr�mentation du j, pour que le programme �crive au rang suivant dans la structure
			// Grille
			j++;
		}
	}
}

void constructAdjacent() {
	// initialisation du tableau adjacent dans la structure Adjacent � 0
	adj.adjacent[16][9] = { 0 };

	//Positions adjacentes � la position 0
	adj.adjacent[0][0] = 3; //Max
	adj.adjacent[0][1] = 1;
	adj.adjacent[0][2] = 4;
	adj.adjacent[0][3] = 5;

	//Positions adjacentes � la position 1
	adj.adjacent[1][0] = 5; //Max
	adj.adjacent[1][1] = 0;
	adj.adjacent[1][2] = 2;
	adj.adjacent[1][3] = 4;
	adj.adjacent[1][4] = 5;
	adj.adjacent[1][5] = 6;

	//Positions adjacentes � la position 2
	adj.adjacent[2][0] = 5; //Max
	adj.adjacent[2][1] = 1;
	adj.adjacent[2][2] = 3;
	adj.adjacent[2][3] = 5;
	adj.adjacent[2][4] = 6;
	adj.adjacent[2][5] = 7;

	//Positions adjacentes � la position 3
	adj.adjacent[3][0] = 3; //Max
	adj.adjacent[3][1] = 2;
	adj.adjacent[3][2] = 6;
	adj.adjacent[3][3] = 7;

	//Positions adjacentes � la position 4
	adj.adjacent[4][0] = 5; //Max
	adj.adjacent[4][1] = 0;
	adj.adjacent[4][2] = 1;
	adj.adjacent[4][3] = 5;
	adj.adjacent[4][4] = 8;
	adj.adjacent[4][5] = 9;

	//Positions adjacentes � la position 5
	adj.adjacent[5][0] = 8; //Max
	adj.adjacent[5][1] = 0;
	adj.adjacent[5][2] = 1;
	adj.adjacent[5][3] = 2;
	adj.adjacent[5][4] = 4;
	adj.adjacent[5][5] = 6;
	adj.adjacent[5][6] = 8;
	adj.adjacent[5][7] = 9;
	adj.adjacent[5][8] = 10;

	//Positions adjacentes � la position 6
	adj.adjacent[6][0] = 8; //Max
	adj.adjacent[6][1] = 1;
	adj.adjacent[6][2] = 2;
	adj.adjacent[6][3] = 3;
	adj.adjacent[6][4] = 5;
	adj.adjacent[6][5] = 7;
	adj.adjacent[6][6] = 9;
	adj.adjacent[6][7] = 10;
	adj.adjacent[6][8] = 11;

	//Positions adjacentes � la position 7
	adj.adjacent[7][0] = 5; //Max
	adj.adjacent[7][1] = 2;
	adj.adjacent[7][2] = 3;
	adj.adjacent[7][3] = 6;
	adj.adjacent[7][4] = 10;
	adj.adjacent[7][5] = 11;

	//Positions adjacentes � la position 8
	adj.adjacent[8][0] = 5; //Max
	adj.adjacent[8][1] = 4;
	adj.adjacent[8][2] = 5;
	adj.adjacent[8][3] = 9;
	adj.adjacent[8][4] = 12;
	adj.adjacent[8][5] = 13;

	//Positions adjacentes � la position 9
	adj.adjacent[9][0] = 8; //Max
	adj.adjacent[9][1] = 4;
	adj.adjacent[9][2] = 5;
	adj.adjacent[9][3] = 6;
	adj.adjacent[9][4] = 8;
	adj.adjacent[9][5] = 10;
	adj.adjacent[9][6] = 12;
	adj.adjacent[9][7] = 13;
	adj.adjacent[9][8] = 14;

	//Positions adjacentes � la position 10
	adj.adjacent[10][0] = 8; //Max
	adj.adjacent[10][1] = 5;
	adj.adjacent[10][2] = 6;
	adj.adjacent[10][3] = 7;
	adj.adjacent[10][4] = 9;
	adj.adjacent[10][5] = 11;
	adj.adjacent[10][6] = 13;
	adj.adjacent[10][7] = 14;
	adj.adjacent[10][8] = 15;

	//Positions adjacentes � la position 11
	adj.adjacent[11][0] = 5; //Max
	adj.adjacent[11][1] = 6;
	adj.adjacent[11][2] = 7;
	adj.adjacent[11][3] = 10;
	adj.adjacent[11][4] = 14;
	adj.adjacent[11][5] = 15;

	//Positions adjacentes � la position 12
	adj.adjacent[12][0] = 3; //Max
	adj.adjacent[12][1] = 8;
	adj.adjacent[12][2] = 9;
	adj.adjacent[12][3] = 13;

	//Positions adjacentes � la position 13
	adj.adjacent[13][0] = 5; //Max
	adj.adjacent[13][1] = 8;
	adj.adjacent[13][2] = 9;
	adj.adjacent[13][3] = 10;
	adj.adjacent[13][4] = 12;
	adj.adjacent[13][5] = 14;

	//Positions adjacentes � la position 14
	adj.adjacent[14][0] = 5; //Max
	adj.adjacent[14][1] = 9;
	adj.adjacent[14][2] = 10;
	adj.adjacent[14][3] = 11;
	adj.adjacent[14][4] = 13;
	adj.adjacent[14][5] = 15;

	//Positions adjacentes � la position 15
	adj.adjacent[15][0] = 3; //Max
	adj.adjacent[15][1] = 10;
	adj.adjacent[15][2] = 11;
	adj.adjacent[15][3] = 14;
}

void initVisite() {
	for (unsigned int i = 0; i < 16; i++) {
		vst.visite[i] = false;
	}
}

bool recherche(Mot mot) {
	// pr�condition : longueur du mot comoris entre 1 et 30 inclus
	assert(strlen(mot) >= 1 && strlen(mot) <= 30);
	// Lance la proc�dure initVisite, afin de marquer toutes les lettres de la grille comme 
	// non-visit�es
	initVisite();
	// boucle permettant de parcourir toutes les coordonn�es de la grille, c'est � dire les 16
	// coordonn�es, repr�sent�es par i, un unsigned int
	for (unsigned int i = 0; i < 16; i++) {
		// Condition qui lance la fonction sousRecherche, en envoyant le mot, la position 0 pour
		// repr�senter la premi�re lettre du mot, et la coordonn�e i.
		if (sousRecherche(mot, 0, i)) {
			// Si la condition est respect�e, et donc que sousRecherche renvoie "true", le mot
			// peut �tre plac� dans la grille du Boogle.
			// La fonction recherche renvoie donc "true"
			return true;
		}
	}
	// Si ce n'est pas le cas, le mot ne peut pas �tre plac� dans la grille du Boogle, donc la
	// fonction renvoie "false".
	return false;
}

bool sousRecherche(Mot mot, int pos, unsigned int coord) {
	// Pr�condition : longueur du mot comoris entre 1 et 30 inclus.
	// Cette pr�condition n'est pas utile, car elle a d�j� �t� v�rifi�e dans la fonction recherche,
	// mais je l'ai rajout� par pr�caution.
	assert(strlen(mot) >= 1 && strlen(mot) <= 30);
	// V�rifie si la position est sup�rieur ou �gale � la longueur du mot.
	// Si c'est le cas, toutes les lettres du mot ont �t� v�rifi�es, et donc le mot peut bien �tre
	// plac�. Le programme renvoie alors "true".
	if (pos >= strlen(mot)) return true;
	// V�rifie si la coordonn�e envoy�e est hors-limite.
	// Si c'est le cas, le programme ne peut pas effectuer son test.
	// Le programme renvoie alors "false".
	if (coord < 0 || coord > 15) return false;
	// V�rifie si si la lettre de la grille en "coord" correspond ou pas � la lettre � la position
	// "pos" de la chaine mot.
	// Si c'est le cas, le programme renvoie alors "false", afin de passer � la coordonn�e suivante.
	if (gr.grille[coord] != mot[pos]) return false;
	// V�rifie si si la lettre de la grille en "coord" est marqu�e comme �tant visit�e.
	// Si c'est le cas, le programme renvoie alors "false", afin de passer � la coordonn�e suivante,
	// car une lettre ne peut pas �tre visit�e 2 fois.
	if (vst.visite[coord] == true) return false;
	// Si toutes les conditions du dessus sont pass�es (la coordonn�e n'est pas hors limite,
	// la lettre de la grille en "coord" correspond ou pas � la lettre � la position "pos" et
	// la lettre n'est pas marqu�e comme visit�e), la lettre peut alors �tre plac�e sur la
	// grille du Boogle : elle est donc marqu�e comme visit�e.
	vst.visite[coord] = true;
	// Boucle envoyant � la m�me fonction les positions suivantes une � une, pour chaque coordonn�e
	// adjacente.
	for (unsigned int i = 1; i <= adj.adjacent[coord][0]; i++) {
		// Si toutes les lettres suivantes peuvent �tre plac�es, elle renvoie "true", pour que la
		// fonction recherche re�oive et envoie "true" � son tour.
		if (sousRecherche(mot, pos + 1, adj.adjacent[coord][i])) return true;
	}
	// Si ce n'est pas le cas, la lettre plac�e est remise comme non-visit�e, car elle n'est au final
	// pas utilis�e.
	vst.visite[coord] = false;
	// Le programme renvoie "false", car le mot ne peut pas �tre plac�.
	return false;
}

void sprint6() {
	// initialise la variable mot de type Mot � 0
	Mot mot;

	// Initialisation de la variable i � 0, un unsigned int car il ne va jamais �tre n�gatif.
	// Cette variable correspond � la ligne � laquelle le programme va �crire le mot dans le
	// conteneur c6.
	unsigned int i = 0;

	// initialisation du conteneur c7, de capacit� 1 et de pas d'extension 1
	initialiser(c7, 1, 1);
	// Ces deux instructions servent a mettre dans le conteneur, � la position 0, la valeur " ",
	// comme �a le conteneur est en quelque sorte "initialis�", au cas ou l'utilisateur ne rentre
	// aucune valeur.
	strcpy_s(mot, " ");
	ecrire(c7, 0, mot);

	// Lancement de la proc�dure constructGrille, afin de construire la grille de Boogle gr�ce aux
	// 4 premiers mots entr�s.
	constructGrille();
	// Lancement de la proc�dure constructAdjacent, afin d'initialiser la structure Visite.
	constructAdjacent();

	// Boucle servant a entrer une liste de mot, tant que "*" n'est pas rentr�, c'est � dire tant
	// que la liste n'est pas fini.
	while (strcmp("*", mot) != 0) {
		// entr�e du mot � l'�cran
		cin >> mot;
		// condition permettant de savoir si le mot entr� est "*" ou non, afin de ne pas le
		// rechercher dans le conteneur
		if (strcmp("*", mot) != 0) {
			// Cette condition permet deux choses.
			// Tout d'abord, de savoir si le mot entr� peut �tre plac� sur la grille, gr�ce � la
			// fonction recherche.
			// Ensuite, elle permet de savoir si le mot est un doublon, qui a �t� d�j� �crit dans
			// le conteneur c7.
			if (recherche(mot) && doublon(c7, mot, c7.capacite) == false) {
				// si les deux conditions sont respect�es, le programme �crit le mot dans le
				// conteneur c7
				ecrire(c7, i, mot);
				// incr�mentation du i, pour que le programme puisse �crire � la position suivante
				// la prochaine fois
				i++;
			}
		}
		
	}
	// tri du conteneur c7, � partir de la position 0
	tri(c7, 0);
	// affiche le conteneur en entier, de la position 0 � la fin
	affiche(c7, 0, c7.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c7, car le programme est fini
	detruire(c7);
}