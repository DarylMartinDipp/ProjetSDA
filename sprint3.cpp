/**
 * @file sprint3.cpp
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * à l'écran les mots de la seconde liste n'apparaissant pas dans la première.
 */

#include <iostream>
#include "sprint2.h"

using namespace std;

ConteneurTDE c1;
ConteneurTDE c2;

unsigned int ecritListe(ConteneurTDE& c1, unsigned int nbe) {
	// Dans cette fonction, la variable nbe va correspondre à l'indice auquel il faut écrire le
	// mot dans le conteneur, mais va donc aussi compter le nombre de mot dans la liste.
	// Si le paramètre nbe n'est pas nul, alors le nombre de mot dans la liste va s'additionner à nbe.

	// initialise la variable mot de type Mot à 0
	Mot mot = { 0 };
	// Boucle servant à prendre la liste de mot en entière, se terminant par *
	// Je compare donc "*" au mot (grâce à strcmp), et si le mot est "*" alors le programme s'arrête.
	// Le programme va donc enregistrer "*" dans les deux listes, mais ne va pas l'afficher car
	// il doit afficher à l'écran les mots de la seconde liste n'apparaissant pas dans la première,
	// ce qui n'est pas le cas de "*".
	while (strcmp("*", mot) != 0) {
		// entrée du mot à l'écran
		cin >> mot;
		// condition permettant de savoir si le mot entré est "*" ou non, afin de ne pas l'écrire
		// dans le conteneur
		if (strcmp("*", mot) != 0) {
			// écrit dans le conteneur le mot à la position nbe
			ecrire(c1, nbe, mot);
			// incrémentation de la variable nbe
			nbe++;
		}
	}
	// renvoie la valeur nbe
	return nbe;
}

void sprint3() {
	// initialise la variable mot de type Mot à 0
	Mot mot = { 0 };
	// initialisation du conteneur c1, de capacité 1 et de pas d'extension 1
	initialiser(c1, 1, 1);
	// initialisation du conteneur c2, de capacité 1 et de pas d'extension 1
	initialiser(c2, 1, 1);
	// Ces deux instructions servent a mettre dans le conteneur, à la position 0, la valeur " ",
	// comme ça le conteneur est en quelque sorte "initialisé", au cas ou l'utilisateur ne rentre
	// aucune valeur.
	strcpy_s(mot, " ");
	ecrire(c2, 0, mot);
	// Initialisation de la variable i à 0, un unsigned int car il ne va jamais être négatif.
	// Cette variable correspond à la ligne à laquelle le programme va écrire le mot dans le
	// conteneur c2.
	unsigned int i = 0;
	// Initialisation de la variable nombreListe1, qui correspond au nombre de mot de la liste 1.
	// Cette valeur va être renvoyée par la fonction ecritListe.
	unsigned int nombreListe1 = ecritListe(c1, 0);
	// Initialisation de la variable nombreTotal, qui correspond au nombre total de mot du
	// conteneur c1.
	// Cette valeur va être renvoyée par la fonction ecritListe, qui va additionner nombreListe1
	// au nombre de mot de la liste 2, car j'ai entré nombreListe1 en paramètre.
	unsigned int nombreTotal = ecritListe(c1, nombreListe1);
	// boucle qui va parcourir le conteneur c1 grâce à la variable nombreListe1,
	// à partir du début de la seconde liste (qui commence à la position nombreListe1,
	// jusqu'à la fin (nombreTotal)
	while (nombreListe1 < nombreTotal) {
		// vérifie si le mot à la position nombreListe1 est un doublon
		if (doublon(c1, c1.tab[nombreListe1], nombreListe1) == false) {
			// Si les conditions sont respectées, le programme écrit le mot à la position i dans
			// le conteneur c2.
			// Par conséquent, les mots écrits dans le conteneur c2 ne sont que les mots désirés.
			ecrire(c2, i, c1.tab[nombreListe1]);
			// incrémentation du i, pour que le programme puisse écrire à la position suivante
			// la prochaine fois
			i++;
		}
	// incrémentation de la variable nombreListe1, pour que le programme puisse lire le mot à la
	// position suivante
	nombreListe1++;
	}
	// tri du conteneur c, à partir de la position 0
	tri(c2, 0);
	// affiche le conteneur en entier, de la position 0 à la fin
	affiche(c2, 0, c2.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c1, car le programme est fini
	detruire(c1);
	// destruction du conteneur c2, car le programme est fini
	detruire(c2);
}