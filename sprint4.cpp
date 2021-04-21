/**
 * @file sprint4.cpp
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * � l'�cran les mots de la seconde liste apparaissant dans la premi�re.
 */
#include <iostream>
#include "sprint2.h"
#include "sprint3.h"

using namespace std;

ConteneurTDE c3;
ConteneurTDE c4;

void sprint4() {
	// initialise la variable mot de type Mot � 0
	Mot mot = { 0 };
	// initialisation du conteneur c3, de capacit� 1 et de pas d'extension 1
	initialiser(c3, 1, 1);
	// initialisation du conteneur c4, de capacit� 1 et de pas d'extension 1
	initialiser(c4, 1, 1);
	// Ces deux instructions servent a mettre dans le conteneur, � la position 0, la valeur " ",
	// comme �a le conteneur est en quelque sorte "initialis�", au cas ou l'utilisateur ne rentre
	// aucune valeur.
	strcpy_s(mot, " ");
	ecrire(c4, 0, mot);
	// Initialisation de la variable k � 0, un unsigned int car il ne va jamais �tre n�gatif.
	// Cette variable correspond � la ligne � laquelle le programme va �crire le mot dans le
	// conteneur c4.
	unsigned int k = 0;
	// Initialisation de la variable nombreListe1, qui correspond au nombre de mot de la liste 1.
	// Cette valeur va �tre renvoy�e par la fonction ecritListe.
	unsigned int nombreListe1 = ecritListe(c3, 0);
	// Initialisation de la variable nombreTotal, qui correspond au nombre total de mot du
	// conteneur c3.
	// Cette valeur va �tre renvoy�e par la fonction ecritListe, qui va additionner nombreListe1
	// au nombre de mot de la liste 2, car j'ai entr� nombreListe1 en param�tre.
	unsigned int nombreTotal = ecritListe(c3, nombreListe1);
	// Boucle qui va parcourir tous les mots de la liste 1, gr�ce � la variable i, car elle
	// s'arr�te avant nombreListe1, c'est � dire au rang du dernier mot de la liste 1.
	// Elle va servir � rechercher si ces mots font partie de la deuxi�me liste ou non.
	for (unsigned int i = 0; i < nombreListe1; i++) {
		// Boucle qui va parcourir tous les mots de la liste 2, gr�ce � la variable j, car elle
		// commence � nombreListe1, c'est � dire au rang du premier mot de la liste 2, et
		// s'arr�te avant nombreTotal, c'est � dire au rang du dernier mot de la liste 2.
		for (unsigned int j = nombreListe1; j < nombreTotal; j++) {
			// comparaison entre le mot de la premi�re liste au rang i au mot de la seconde liste
			// au rang j gr�ce � strcmp
			if (strcmp(c3.tab[i], c3.tab[j]) == 0) {
				// si les deux mots sont identiques, strcmp renvoie 0 et le programme peut �crire ce mot
				// dans le conteneur c4, au rang k
				ecrire(c4, k, c3.tab[i]);
				// incr�mentation du k, pour que le programme puisse �crire � la position suivante
				// la prochaine fois
				k++;
				// Ce break sert � que, une fois que le programme trouve une correspondance avec le mot
				// de la premi�re liste, il passe directement au mot suivant.
				// Aucun doublon n'est alors �crit dans le conteneur c4.
				break;
			}
		}
	}
	// Affiche le conteneur c4 en entier, de la position 0 � la fin.
	affiche(c4, 0, c4.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c3, car le programme est fini
	detruire(c3);
	// destruction du conteneur c4, car le programme est fini
	detruire(c4);
}