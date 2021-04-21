#pragma once

/**
 * @file sprint5.h
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * à l'écran la liste de tous les mots apparaissant dans au moins deux de ces listes.
 */

// STRUCTURE ------------------------------------------------------------------

/**
 * @brief Structure contenant le rang de début de chaque liste dans le conteneur.
 * Elle contient, dans la première ligne de son tableau, la valeur 0.
 */

// J'ai laissé dans le .cpp l'affichage de la structure que j'avais codé afin d'essayer de débugger
// mon programme, si cela peut aider la compréhension de cette structure.

struct Debut {
	// Entier contenant le nombre total de listes entrées.
	// C'est un unsigned int car il ne peut pas contenir de valeur négative.
	unsigned int nbListe;
	// Tableau comportant le rang de début de chaque liste dans le conteneur.
	int tab[50];
};

// FONCTIONS ------------------------------------------------------------------

/**
 * @brief Ecrit les listes de mots dans le conteneur souhaité, et rempli la structure Debut
 * automatiquement.
 * @see la fonction ecritListe du sprint3.h.
 * @see la structure Debut.
 */
void constructTabDebut(ConteneurTDE& c);

/**
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * à l'écran la liste de tous les mots apparaissant dans au moins deux de ces listes.
 * @see la fonction initialiser du ConteneurTDE.h.
 * @see la fonction constructTabDebut.
 * @see la fonction doublon du sprint2.h.
 * @see la fonction ecrire du ConteneurTDE.h.
 * @see la fonction tri du sprint2.h.
 * @see la fonction affiche du sprint2.h.
 * @see la fonction detruire du ConteneurTDE.h.
 * @see la structure Debut.
 */
void sprint5();