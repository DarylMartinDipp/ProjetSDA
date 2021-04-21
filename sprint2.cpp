/**
 * @file sprint2.cpp
 * @brief Lire une liste de mots saisie au clavier et l'afficher
 * � l'�cran sous forme canonique.
 */

#include <iostream>
#include <cassert>

#include "sprint2.h"

using namespace std;

ConteneurTDE c;

bool doublon(ConteneurTDE& c, Mot mot, unsigned int capacite) {
	// pr�condition : longueur du mot comoris entre 1 et 30 inclus
	assert(strlen(mot) >= 1 && strlen(mot) <= 30);
	// boucle servant � lire une par une les valeurs d'un conteneur,
	// gr�ce au i qui varie entre 0 et la capacit� (le maximum) entr�e
	for (unsigned int i = 0; i < capacite; i++) {
		// comparaison entre la valeur lue � la position i et le mot entr�
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
	// initialise la variable tampon de type Mot � 0
	// cette variable va servir � stocker le mot "tampon"
	Mot tampon = { 0 };
	// boucle qui va parcourir le conteneur gr�ce � la variable d�but,
	// � partir du d�but entr�, jusqu'� la fin (c.capacite - 1)
	for (debut; debut <= c.capacite - 1; debut++) {
		// boucle qui va parcourir le conteneur, � partir du deuxi�me mot (d�but + 1),
		// jusqu'� la fin (c.capacite - 1)
		// Ces deux boucles vont permettre de comparer deux mots adjacents
		for (unsigned int i = debut + 1; i <= c.capacite - 1; i++) {
			// Compare les deux mots adjacents gr�ce � strcmp, en regardant si ces deux mots
			// sont ou ne sont pas class�s par ordre alphab�tique.
			// Si strcmp renvoie 1, alors ces deux mots ne le sont pas, et le programme
			// doit les intervertir.
			if (strcmp(c.tab[debut], c.tab[i]) == 1) {
				// sauvegarde gr�ce � strcpy le mot de position sup�rieure dans le mot tampon
				strcpy_s(tampon, c.tab[i]);
				// copie gr�ce � strcpy le mot de position sup�rieure � la place du mot de position
				// inf�rieure
				strcpy_s(c.tab[i], c.tab[debut]);
				// copie gr�ce � strcpy le mot de position sup�rieure (sauvegard� dans tampon)
				// � la place du mot de position inf�rieure
				strcpy_s(c.tab[debut], tampon);
				// les deux mots sont alors intervertis
			}
		}
	}
}

void affiche(ConteneurTDE& c, unsigned int debut, unsigned int fin) {
	// boucle qui va parcourir le conteneur gr�ce � la variable d�but,
	// � partir du d�but entr�, jusqu'� la fin entr�e
	for (debut; debut < fin; debut++) {
		// affiche le mot lu � la position debut, dans le conteneur c
		cout << lire(c, debut) << endl;
	}
}

void sprint2() {
	// initialise la variable mot de type Mot � 0
	Mot mot = { 0 };
	// Initialisation de la variable i � 0, un unsigned int car il ne va jamais �tre n�gatif.
	// Cette variable correspond � la ligne � laquelle le programme va �crire le mot dans le
	// conteneur c.
	unsigned int i = 0;
	// initialisation du conteneur c, de capacit� 1 et de pas d'extension 1
	initialiser(c, 1, 1);
	// Ces deux instructions servent a mettre dans le conteneur, � la position 0, la valeur " ",
	// comme �a le conteneur est en quelque sorte "initialis�", au cas ou l'utilisateur ne rentre
	// aucune valeur.
	strcpy_s(mot, " ");
	ecrire(c, 0, mot);
	// Boucle servant � prendre la liste de mot en enti�re, se terminant par *
	// Je compare donc "*" au mot (gr�ce � strcmp), et si le mot est "*" alors le programme s'arr�te
	while (strcmp("*", mot) != 0) {
		// entr�e du mot � l'�cran
		cin >> mot;
		// V�rifie si le mot est un doublon par rapport aux mots du conteneur c, jusqu'� la ligne
		// c.capacite.
		// Si ce n'est pas le cas, le programme continue.
		// V�rifie aussi si le mot est "*", pour ne pas que le "*" tap� � la fin de la liste
		// soit �crit dans le conteneur.
		if (doublon(c, mot, c.capacite) == false && strcmp("*", mot) != 0) {
			// Si les conditions sont respect�es, le programme �crit le mot � la position i dans
			// le conteneur c.
			// Par cons�quent, les mots �crits dans le conteneur c ne sont que les mots d�sir�s.
			ecrire(c, i, mot);
			// incr�mentation du i, pour que le programme puisse �crire � la position suivante la
			// prochaine fois
			i++;
		}
	}
	// tri du conteneur c, � partir de la position 0
	tri(c, 0);
	// affiche le conteneur en entier, de la position 0 � la fin
	affiche(c, 0, c.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c, car le programme est fini
	detruire(c);
}
