/**
 * @file sprint4.cpp
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * à l'écran les mots de la seconde liste apparaissant dans la première.
 */
#include <iostream>
#include "sprint2.h"
#include "sprint3.h"

using namespace std;

ConteneurTDE c3;
ConteneurTDE c4;

void sprint4() {
	// initialise la variable mot de type Mot à 0
	Mot mot = { 0 };
	// initialisation du conteneur c3, de capacité 1 et de pas d'extension 1
	initialiser(c3, 1, 1);
	// initialisation du conteneur c4, de capacité 1 et de pas d'extension 1
	initialiser(c4, 1, 1);
	// Ces deux instructions servent a mettre dans le conteneur, à la position 0, la valeur " ",
	// comme ça le conteneur est en quelque sorte "initialisé", au cas ou l'utilisateur ne rentre
	// aucune valeur.
	strcpy_s(mot, " ");
	ecrire(c4, 0, mot);
	// Initialisation de la variable k à 0, un unsigned int car il ne va jamais être négatif.
	// Cette variable correspond à la ligne à laquelle le programme va écrire le mot dans le
	// conteneur c4.
	unsigned int k = 0;
	// Initialisation de la variable nombreListe1, qui correspond au nombre de mot de la liste 1.
	// Cette valeur va être renvoyée par la fonction ecritListe.
	unsigned int nombreListe1 = ecritListe(c3, 0);
	// Initialisation de la variable nombreTotal, qui correspond au nombre total de mot du
	// conteneur c3.
	// Cette valeur va être renvoyée par la fonction ecritListe, qui va additionner nombreListe1
	// au nombre de mot de la liste 2, car j'ai entré nombreListe1 en paramètre.
	unsigned int nombreTotal = ecritListe(c3, nombreListe1);
	// Boucle qui va parcourir tous les mots de la liste 1, grâce à la variable i, car elle
	// s'arrête avant nombreListe1, c'est à dire au rang du dernier mot de la liste 1.
	// Elle va servir à rechercher si ces mots font partie de la deuxième liste ou non.
	for (unsigned int i = 0; i < nombreListe1; i++) {
		// Boucle qui va parcourir tous les mots de la liste 2, grâce à la variable j, car elle
		// commence à nombreListe1, c'est à dire au rang du premier mot de la liste 2, et
		// s'arrête avant nombreTotal, c'est à dire au rang du dernier mot de la liste 2.
		for (unsigned int j = nombreListe1; j < nombreTotal; j++) {
			// comparaison entre le mot de la première liste au rang i au mot de la seconde liste
			// au rang j grâce à strcmp
			if (strcmp(c3.tab[i], c3.tab[j]) == 0) {
				// si les deux mots sont identiques, strcmp renvoie 0 et le programme peut écrire ce mot
				// dans le conteneur c4, au rang k
				ecrire(c4, k, c3.tab[i]);
				// incrémentation du k, pour que le programme puisse écrire à la position suivante
				// la prochaine fois
				k++;
				// Ce break sert à que, une fois que le programme trouve une correspondance avec le mot
				// de la première liste, il passe directement au mot suivant.
				// Aucun doublon n'est alors écrit dans le conteneur c4.
				break;
			}
		}
	}
	// Affiche le conteneur c4 en entier, de la position 0 à la fin.
	affiche(c4, 0, c4.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c3, car le programme est fini
	detruire(c3);
	// destruction du conteneur c4, car le programme est fini
	detruire(c4);
}