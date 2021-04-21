#pragma once

/**
 * @file sprint6.cpp
 * @brief Lire un plateau suivi d'une liste de mots saisis au clavier
 * et afficher � l'�cran les mots de la liste �tant pr�sents sur la plateau.
 */

// STRUCTURES -----------------------------------------------------------------

 /** @brief Structure contenant la grille des 16 lettres du Boogle.
  */
struct Grille {
	// Tableau de 16 caract�res contenant les 16 lettres du Boogle.
	char grille[16];
};

/** @brief Structure contenant la liste des num�ros des cellules adjacentes � la cellules en cours.
 *  Exemple : ligne 0 (cellule 00 de mon tableau) : les positions adjacentes sont 01 - 04 - 05.
 *  00 01 02 03
 *  04 05 06 07
 *  08 09 10 11
 *  12 13 14 15
 *  Le premier poste de la ligne est le max.
 */
struct Adjacent {
	// Tableau � double entr�e contenant 16 lignes pour les 16 lettres du Boogle
	// et 9 colonnes : 1 contenant le nombre maximum de cellules adjacentes ;
	//				   8 contenant le num�ro des 8 cellules adjacentes maximums.
	unsigned int adjacent[16][9];
};

/** @brief Structure permettant de connaitre si une lettre de la grille est visit�e ou non. 
 */
struct Visite {
	// Tableau de 16 bool�ens renvoyant True si la lettre est visit�e, False si elle ne l'est pas.
	bool visite[16];
};

// FONCTIONS ------------------------------------------------------------------

/**
 * @brief Initialise la grille du Boogle.
 * Rentre les 4 mots sous formes de lettres, en les mettant dans le tableau contenu dans
 * la structure "Grille" (gr).
 * @pre La grille doit �tre rentr�e sous forme de 4 mots.
 * @see la structure Grille.
 */
void constructGrille();

/**
 * @brief Initialise automatiquement la structure "Adjacent" (adj), gr�ce � des valeurs brutes
 * constantes rentr�es par le cr�ateur du programme.
 * @see la structure Adjacent.
 */
void constructAdjacent();

/**
 * @brief Initialise la structure "Visite" (vst) en marquant toutes les lettres
 * de la grille comme �tant non visit�es.
 * @see la structure Visite.
 */
void initVisite();

/**
 * @brief Recherche si un mot entr� par l'utilisateur peut bel et bien �tre plac� dans la grille.
 * @param[in] mot le mot entr� par l'utilisateur.
 * @see la fonction initViste.
 * @see la fonction sousRecherche.
 * @return true si le mot peut �tre plac� dans la grille du Boogle.
 * @return false si le mot ne peut pas �tre plac� dans la grille du Boogle.
 * @pre longueur du mot compris entre 1 et 30 inclus.
 */
bool recherche(Mot mot);
/**
 * @brief D�termine si le mot commen�ant � la position pos peut �tre plac� � partir
 * de la coordonn�e coord.
 * @param[in] mot le mot entr� par l'utilisateur.
 * @param[in] pos la position de la lettre dans le mot.
 * @param[in] coord la coordonn�e de la lettre � comparer dans la gille du Boogle.
 * @see la fonction recherche.
 * @see la structure Grille.
 * @see la structure Adjacent.
 * @see la structure Visite.
 * @return true si le mot commen�ant � la position pos peut �tre plac� � partir
 * de la coordonn�e coord.
 * @return false si le mot commen�ant � la position pos ne peut pas �tre plac� � partir
 * de la coordonn�e coord.
 * @pre longueur du mot compris entre 1 et 30 inclus.
 */
bool sousRecherche(Mot mot, int pos, unsigned int coord);

/**
 * @brief Lire un plateau suivi d'une liste de mots saisis au clavier
 * et afficher � l'�cran les mots de la liste �tant pr�sents sur la plateau.
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