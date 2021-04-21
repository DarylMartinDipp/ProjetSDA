#pragma once

/**
 * @file sprint2.h
 * @brief Lire une liste de mots saisie au clavier et l'afficher
 * à l'écran sous forme canonique.
 */

#include "ConteneurTDE.h"

/**
 * @brief Cherche si au moins un mot est en doublon dans une partie ou la totalité d'un conteneur.
 * @param [in,out] c le conteneur de mot.
 * @param [in] mot le mot rentré par l'utilisateur.
 * @param [in] capacite le nombre de mot a trier.
 * @see la fonction lire du ConteneurTDE.h.
 * @return true si l'un des mots est un doublon.
 * @return false si aucun mot n'est un doublon.
 * @pre longueur du mot compris entre 1 et 30 inclus.
 */
bool doublon(ConteneurTDE& c, Mot mot, unsigned int capacite);

/**
 * @brief Trie une partie ou la totalité d'un conteneur par ordre alphabétique, d'après le tri à bulle.
 * @param [in,out] c le conteneur de mot.
 * @param[in] debut la position du premier mot a trier.
 */
void tri(ConteneurTDE& c, unsigned int debut);

/**
 * @brief affiche le contenu d'une partie ou de la totalité d'un conteneur.
 * @param [in,out] c le conteneur de mot.
 * @param[in] debut la position du premier mot a trier.
 * @param[in] fin la position du dernier mot a trier.
 * @see la fonction lire du ConteneurTDE.h.
 */
void affiche(ConteneurTDE& c, unsigned int debut, unsigned int fin);

/**
 * @brief Lire une liste de mots saisie au clavier et l'afficher
 * à l'écran sous forme canonique.
 * @see la fonction initialiser du ConteneurTDE.h.
 * @see la fonction ecrire du ConteneurTDE.h.
 * @see la fonction tri.
 * @see la fonction affiche.
 * @see la fonction detruire du ConteneurTDE.h.
 */
void sprint2();