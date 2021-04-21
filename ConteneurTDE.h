#pragma once

/**
 * @file ConteneurTDE.h
 * @brief Composant d'un conteneur de mots de capacit� extensible.
 */

#include "Mot.h"

/** @brief Conteneur de mots allou�s en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension.
 */ 
struct ConteneurTDE {
	/// Capacit� du conteneur (>0).
    unsigned int capacite; 	   
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension; 
	/// Conteneur allou� en m�moire dynamique.
	Mot* tab;			   
};

/**
 * @brief Initialise un conteneur d'Mots.
 * Allocation en m�moire dynamique du conteneur de mots
 * de capacit� (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa d�sallocation en fin d'utilisation. 
 * @param[out] c Le conteneur de mots.
 * @param [in] capa Capacit� du conteneur.
 * @param [in] p Pas d'extension de capacit�.
 * @pre capa > 0 et p > 0.
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);

/**
 * @brief D�salloue un conteneur de mots en m�moire dynamique.
 * @see initialiser. 
 * @param[in,out] c Le conteneur de mots.
 */
void detruire(ConteneurTDE& c); 

/**
 * @brief Lecture d'un mot d'un conteneur d'Mots.
 * @param[in] c Le conteneur de mots.
 * @param[in] i La position de le mot dans le conteneur.
 * @return Le mot � la position i.
 * @pre i < c.capacite
 */
 char* lire(const ConteneurTDE& c, unsigned int i);

/**
 * @brief Ecrire un mot dans un conteneur de mots.
 * @param[in,out] c Le conteneur de mots.
 * @param[in] i La position o� ajouter/modifier le mot.
 * @param[in] it Le mot � �crire.
 */
void ecrire(ConteneurTDE& c, unsigned int i, const Mot& it);
