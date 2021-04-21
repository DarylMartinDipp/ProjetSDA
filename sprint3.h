#pragma once

/**
 * @file sprint3.h
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * � l'�cran les mots de la seconde liste n'apparaissant pas dans la premi�re.
 */

 /**
  * @brief Ecrit les mots d'une liste dans un conteneur, tout en renvoyant � la fin le nombre
  * d'occurences.
  * @param [in,out] c1 le conteneur de mot.
  * @param[in] nbe le nombre de mot a ajouter au nombre de mots de la liste pr�sente.
  * @see la fonction ecrire du ConteneurTDE.h.
  * @return le nombre de mot total, �gal � nbe + le nombre de mot de la liste pr�sente.
  */
unsigned int ecritListe(ConteneurTDE& c1, unsigned int nbe);

/**
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * � l'�cran les mots de la seconde liste n'apparaissant pas dans la premi�re.
 * @see la fonction initialiser du ConteneurTDE.h.
 * @see la fonction ecritListe.
 * @see la fonction initialiser du ConteneurTDE.h.
 * @see la fonction doublon du sprint2.h.
 * @see la fonction ecrire du ConteneurTDE.h.
 * @see la fonction tri du sprint2.h.
 * @see la fonction affiche du sprint2.h.
 * @see la fonction detruire du ConteneurTDE.h.
 */
void sprint3();