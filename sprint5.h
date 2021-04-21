#pragma once

/**
 * @file sprint5.h
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * � l'�cran la liste de tous les mots apparaissant dans au moins deux de ces listes.
 */

// STRUCTURE ------------------------------------------------------------------

/**
 * @brief Structure contenant le rang de d�but de chaque liste dans le conteneur.
 * Elle contient, dans la premi�re ligne de son tableau, la valeur 0.
 */

// J'ai laiss� dans le .cpp l'affichage de la structure que j'avais cod� afin d'essayer de d�bugger
// mon programme, si cela peut aider la compr�hension de cette structure.

struct Debut {
	// Entier contenant le nombre total de listes entr�es.
	// C'est un unsigned int car il ne peut pas contenir de valeur n�gative.
	unsigned int nbListe;
	// Tableau comportant le rang de d�but de chaque liste dans le conteneur.
	int tab[50];
};

// FONCTIONS ------------------------------------------------------------------

/**
 * @brief Ecrit les listes de mots dans le conteneur souhait�, et rempli la structure Debut
 * automatiquement.
 * @see la fonction ecritListe du sprint3.h.
 * @see la structure Debut.
 */
void constructTabDebut(ConteneurTDE& c);

/**
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * � l'�cran la liste de tous les mots apparaissant dans au moins deux de ces listes.
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