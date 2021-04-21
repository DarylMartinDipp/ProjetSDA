#pragma once

/**
 * @file sprint6.cpp
 * @brief Lire un plateau suivi d'une liste de mots saisis au clavier
 * et afficher à l'écran les mots de la liste étant présents sur la plateau.
 */

// STRUCTURES -----------------------------------------------------------------

 /** @brief Structure contenant la grille des 16 lettres du Boogle.
  */
struct Grille {
	// Tableau de 16 caractères contenant les 16 lettres du Boogle.
	char grille[16];
};

/** @brief Structure contenant la liste des numéros des cellules adjacentes à la cellules en cours.
 *  Exemple : ligne 0 (cellule 00 de mon tableau) : les positions adjacentes sont 01 - 04 - 05.
 *  00 01 02 03
 *  04 05 06 07
 *  08 09 10 11
 *  12 13 14 15
 *  Le premier poste de la ligne est le max.
 */
struct Adjacent {
	// Tableau à double entrée contenant 16 lignes pour les 16 lettres du Boogle
	// et 9 colonnes : 1 contenant le nombre maximum de cellules adjacentes ;
	//				   8 contenant le numéro des 8 cellules adjacentes maximums.
	unsigned int adjacent[16][9];
};

/** @brief Structure permettant de connaitre si une lettre de la grille est visitée ou non. 
 */
struct Visite {
	// Tableau de 16 booléens renvoyant True si la lettre est visitée, False si elle ne l'est pas.
	bool visite[16];
};

// FONCTIONS ------------------------------------------------------------------

/**
 * @brief Initialise la grille du Boogle.
 * Rentre les 4 mots sous formes de lettres, en les mettant dans le tableau contenu dans
 * la structure "Grille" (gr).
 * @pre La grille doit être rentrée sous forme de 4 mots.
 * @see la structure Grille.
 */
void constructGrille();

/**
 * @brief Initialise automatiquement la structure "Adjacent" (adj), grâce à des valeurs brutes
 * constantes rentrées par le créateur du programme.
 * @see la structure Adjacent.
 */
void constructAdjacent();

/**
 * @brief Initialise la structure "Visite" (vst) en marquant toutes les lettres
 * de la grille comme étant non visitées.
 * @see la structure Visite.
 */
void initVisite();

/**
 * @brief Recherche si un mot entré par l'utilisateur peut bel et bien être placé dans la grille.
 * @param[in] mot le mot entré par l'utilisateur.
 * @see la fonction initViste.
 * @see la fonction sousRecherche.
 * @return true si le mot peut être placé dans la grille du Boogle.
 * @return false si le mot ne peut pas être placé dans la grille du Boogle.
 * @pre longueur du mot compris entre 1 et 30 inclus.
 */
bool recherche(Mot mot);
/**
 * @brief Détermine si le mot commençant à la position pos peut être placé à partir
 * de la coordonnée coord.
 * @param[in] mot le mot entré par l'utilisateur.
 * @param[in] pos la position de la lettre dans le mot.
 * @param[in] coord la coordonnée de la lettre à comparer dans la gille du Boogle.
 * @see la fonction recherche.
 * @see la structure Grille.
 * @see la structure Adjacent.
 * @see la structure Visite.
 * @return true si le mot commençant à la position pos peut être placé à partir
 * de la coordonnée coord.
 * @return false si le mot commençant à la position pos ne peut pas être placé à partir
 * de la coordonnée coord.
 * @pre longueur du mot compris entre 1 et 30 inclus.
 */
bool sousRecherche(Mot mot, int pos, unsigned int coord);

/**
 * @brief Lire un plateau suivi d'une liste de mots saisis au clavier
 * et afficher à l'écran les mots de la liste étant présents sur la plateau.
 * @see la fonction initialiser du ConteneurTDE.h.
 * @see la fonction constructGrille.
 * @see la fonction constructAdjacent.
 * @see la fonction recherche.
 * @see la fonction doublon du sprint2.h.
 * @see la fonction ecrire du ConteneurTDE.h.
 * @see la fonction tri du sprint2.h.
 * @see la fonction affiche du sprint2.h.
 * @see la fonction detruire du ConteneurTDE.h.
 */
void sprint6();