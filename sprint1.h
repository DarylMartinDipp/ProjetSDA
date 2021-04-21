#pragma once

#include "Mot.h"

/**
 * @file sprint1.h
 * @brief Lire une liste de mots saisie au clavier et afficher
 * � l'�cran le nombre de points qu'elle repr�sente.
 */

/**
 * @brief Compte le nombre de points d'un seul mot.
 * @param [in] mot le mot rentr� par l'utilisateur.
 * @see la fonction compteurPts.
 * @return le nombre de points du mot entr�.
 * @pre longueur du mot comoris entre 1 et 30 inclus.
 */
int nbePts(Mot mot);

/**
 * @brief Compte le nombre de points total d'une liste de mot.
 * @see la fonction nbePts.
 * @return le nombre de points total d'une liste de mot.
 */
unsigned int compteurPts();

/**
 * @brief Lire une liste de mots saisie au clavier et afficher
 * � l'�cran le nombre de points qu'elle repr�sente.
 * @see la fonction nbePts.
 * @see la fonction compteurPts.
 */
void sprint1();