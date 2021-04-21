#pragma once

/**
 * @file ConteneurTDE.h
 * @brief Composant d'un conteneur de mots de capacité extensible.
 */

#include "Mot.h"

/** @brief Conteneur de mots alloués en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension.
 */ 
struct ConteneurTDE {
	/// Capacité du conteneur (>0).
    unsigned int capacite; 	   
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension; 
	/// Conteneur alloué en mémoire dynamique.
	Mot* tab;			   
};

/**
 * @brief Initialise un conteneur d'Mots.
 * Allocation en mémoire dynamique du conteneur de mots
 * de capacité (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa désallocation en fin d'utilisation. 
 * @param[out] c Le conteneur de mots.
 * @param [in] capa Capacité du conteneur.
 * @param [in] p Pas d'extension de capacité.
 * @pre capa > 0 et p > 0.
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);

/**
 * @brief Désalloue un conteneur de mots en mémoire dynamique.
 * @see initialiser. 
 * @param[in,out] c Le conteneur de mots.
 */
void detruire(ConteneurTDE& c); 

/**
 * @brief Lecture d'un mot d'un conteneur d'Mots.
 * @param[in] c Le conteneur de mots.
 * @param[in] i La position de le mot dans le conteneur.
 * @return Le mot à la position i.
 * @pre i < c.capacite
 */
 char* lire(const ConteneurTDE& c, unsigned int i);

/**
 * @brief Ecrire un mot dans un conteneur de mots.
 * @param[in,out] c Le conteneur de mots.
 * @param[in] i La position où ajouter/modifier le mot.
 * @param[in] it Le mot à écrire.
 */
void ecrire(ConteneurTDE& c, unsigned int i, const Mot& it);
