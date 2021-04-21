/**
 * @file sprint2.cpp
 * @brief Lire une liste de mots saisie au clavier et l'afficher
 * à l'écran sous forme canonique.
 */

#include <iostream>
#include <cassert>

#include "sprint2.h"

using namespace std;

ConteneurTDE c;

bool doublon(ConteneurTDE& c, Mot mot, unsigned int capacite) {
	// précondition : longueur du mot comoris entre 1 et 30 inclus
	assert(strlen(mot) >= 1 && strlen(mot) <= 30);
	// boucle servant à lire une par une les valeurs d'un conteneur,
	// grâce au i qui varie entre 0 et la capacité (le maximum) entrée
	for (unsigned int i = 0; i < capacite; i++) {
		// comparaison entre la valeur lue à la position i et le mot entré
		if (strcmp (lire(c, i), mot) == 0) {
			// si le mot est lu dans le conteneur, alors ce mot est un doublon, donc
			// le programme renvoie "true"
			return true;
		}
	}
	// sinon, le mot n'est pas un doublon, donc le programme renvoie "false"
	return false;
}

void tri(ConteneurTDE& c, unsigned int debut) {
	// initialise la variable tampon de type Mot à 0
	// cette variable va servir à stocker le mot "tampon"
	Mot tampon = { 0 };
	// boucle qui va parcourir le conteneur grâce à la variable début,
	// à partir du début entré, jusqu'à la fin (c.capacite - 1)
	for (debut; debut <= c.capacite - 1; debut++) {
		// boucle qui va parcourir le conteneur, à partir du deuxième mot (début + 1),
		// jusqu'à la fin (c.capacite - 1)
		// Ces deux boucles vont permettre de comparer deux mots adjacents
		for (unsigned int i = debut + 1; i <= c.capacite - 1; i++) {
			// Compare les deux mots adjacents grâce à strcmp, en regardant si ces deux mots
			// sont ou ne sont pas classés par ordre alphabétique.
			// Si strcmp renvoie 1, alors ces deux mots ne le sont pas, et le programme
			// doit les intervertir.
			if (strcmp(c.tab[debut], c.tab[i]) == 1) {
				// sauvegarde grâce à strcpy le mot de position supérieure dans le mot tampon
				strcpy_s(tampon, c.tab[i]);
				// copie grâce à strcpy le mot de position supérieure à la place du mot de position
				// inférieure
				strcpy_s(c.tab[i], c.tab[debut]);
				// copie grâce à strcpy le mot de position supérieure (sauvegardé dans tampon)
				// à la place du mot de position inférieure
				strcpy_s(c.tab[debut], tampon);
				// les deux mots sont alors intervertis
			}
		}
	}
}

void affiche(ConteneurTDE& c, unsigned int debut, unsigned int fin) {
	// boucle qui va parcourir le conteneur grâce à la variable début,
	// à partir du début entré, jusqu'à la fin entrée
	for (debut; debut < fin; debut++) {
		// affiche le mot lu à la position debut, dans le conteneur c
		cout << lire(c, debut) << endl;
	}
}

void sprint2() {
	// initialise la variable mot de type Mot à 0
	Mot mot = { 0 };
	// Initialisation de la variable i à 0, un unsigned int car il ne va jamais être négatif.
	// Cette variable correspond à la ligne à laquelle le programme va écrire le mot dans le
	// conteneur c.
	unsigned int i = 0;
	// initialisation du conteneur c, de capacité 1 et de pas d'extension 1
	initialiser(c, 1, 1);
	// Ces deux instructions servent a mettre dans le conteneur, à la position 0, la valeur " ",
	// comme ça le conteneur est en quelque sorte "initialisé", au cas ou l'utilisateur ne rentre
	// aucune valeur.
	strcpy_s(mot, " ");
	ecrire(c, 0, mot);
	// Boucle servant à prendre la liste de mot en entière, se terminant par *
	// Je compare donc "*" au mot (grâce à strcmp), et si le mot est "*" alors le programme s'arrête
	while (strcmp("*", mot) != 0) {
		// entrée du mot à l'écran
		cin >> mot;
		// Vérifie si le mot est un doublon par rapport aux mots du conteneur c, jusqu'à la ligne
		// c.capacite.
		// Si ce n'est pas le cas, le programme continue.
		// Vérifie aussi si le mot est "*", pour ne pas que le "*" tapé à la fin de la liste
		// soit écrit dans le conteneur.
		if (doublon(c, mot, c.capacite) == false && strcmp("*", mot) != 0) {
			// Si les conditions sont respectées, le programme écrit le mot à la position i dans
			// le conteneur c.
			// Par conséquent, les mots écrits dans le conteneur c ne sont que les mots désirés.
			ecrire(c, i, mot);
			// incrémentation du i, pour que le programme puisse écrire à la position suivante la
			// prochaine fois
			i++;
		}
	}
	// tri du conteneur c, à partir de la position 0
	tri(c, 0);
	// affiche le conteneur en entier, de la position 0 à la fin
	affiche(c, 0, c.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c, car le programme est fini
	detruire(c);
}
