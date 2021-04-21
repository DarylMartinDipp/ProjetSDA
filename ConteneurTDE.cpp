/**
 * @file ConteneurTDE.cpp
 * @brief Composant de conteneur d'Mots de capacité extensible
 */

#include <iostream>
#include <cassert>
using namespace std;

#include "ConteneurTDE.h"

void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa > 0) && (p > 0));
	c.capacite = capa;
	c.pasExtension = p;
	c.tab = new Mot[capa];
}

void detruire(ConteneurTDE& c) {
	delete[] c.tab;
	c.tab = NULL;
}

char* lire(const ConteneurTDE& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

void ecrire(ConteneurTDE& c, unsigned int i, const Mot& it) {
	if (i >= c.capacite) {
		unsigned int newTaille = (i + 1) * c.pasExtension;
		Mot* newT = new Mot[newTaille];
		for (unsigned int j = 0; j < c.capacite; ++j)
			strcpy_s(newT[j], c.tab[j]);
		delete[] c.tab;
		c.tab = newT;
		c.capacite = newTaille;
	}
	strcpy_s(c.tab[i], it);
}