/**
 * @file sprint3.cpp
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * � l'�cran les mots de la seconde liste n'apparaissant pas dans la premi�re.
 */

#include <iostream>
#include "sprint2.h"

using namespace std;

ConteneurTDE c1;
ConteneurTDE c2;

unsigned int ecritListe(ConteneurTDE& c1, unsigned int nbe) {
	// Dans cette fonction, la variable nbe va correspondre � l'indice auquel il faut �crire le
	// mot dans le conteneur, mais va donc aussi compter le nombre de mot dans la liste.
	// Si le param�tre nbe n'est pas nul, alors le nombre de mot dans la liste va s'additionner � nbe.

	// initialise la variable mot de type Mot � 0
	Mot mot = { 0 };
	// Boucle servant � prendre la liste de mot en enti�re, se terminant par *
	// Je compare donc "*" au mot (gr�ce � strcmp), et si le mot est "*" alors le programme s'arr�te.
	// Le programme va donc enregistrer "*" dans les deux listes, mais ne va pas l'afficher car
	// il doit afficher � l'�cran les mots de la seconde liste n'apparaissant pas dans la premi�re,
	// ce qui n'est pas le cas de "*".
	while (strcmp("*", mot) != 0) {
		// entr�e du mot � l'�cran
		cin >> mot;
		// condition permettant de savoir si le mot entr� est "*" ou non, afin de ne pas l'�crire
		// dans le conteneur
		if (strcmp("*", mot) != 0) {
			// �crit dans le conteneur le mot � la position nbe
			ecrire(c1, nbe, mot);
			// incr�mentation de la variable nbe
			nbe++;
		}
	}
	// renvoie la valeur nbe
	return nbe;
}

void sprint3() {
	// initialise la variable mot de type Mot � 0
	Mot mot = { 0 };
	// initialisation du conteneur c1, de capacit� 1 et de pas d'extension 1
	initialiser(c1, 1, 1);
	// initialisation du conteneur c2, de capacit� 1 et de pas d'extension 1
	initialiser(c2, 1, 1);
	// Ces deux instructions servent a mettre dans le conteneur, � la position 0, la valeur " ",
	// comme �a le conteneur est en quelque sorte "initialis�", au cas ou l'utilisateur ne rentre
	// aucune valeur.
	strcpy_s(mot, " ");
	ecrire(c2, 0, mot);
	// Initialisation de la variable i � 0, un unsigned int car il ne va jamais �tre n�gatif.
	// Cette variable correspond � la ligne � laquelle le programme va �crire le mot dans le
	// conteneur c2.
	unsigned int i = 0;
	// Initialisation de la variable nombreListe1, qui correspond au nombre de mot de la liste 1.
	// Cette valeur va �tre renvoy�e par la fonction ecritListe.
	unsigned int nombreListe1 = ecritListe(c1, 0);
	// Initialisation de la variable nombreTotal, qui correspond au nombre total de mot du
	// conteneur c1.
	// Cette valeur va �tre renvoy�e par la fonction ecritListe, qui va additionner nombreListe1
	// au nombre de mot de la liste 2, car j'ai entr� nombreListe1 en param�tre.
	unsigned int nombreTotal = ecritListe(c1, nombreListe1);
	// boucle qui va parcourir le conteneur c1 gr�ce � la variable nombreListe1,
	// � partir du d�but de la seconde liste (qui commence � la position nombreListe1,
	// jusqu'� la fin (nombreTotal)
	while (nombreListe1 < nombreTotal) {
		// v�rifie si le mot � la position nombreListe1 est un doublon
		if (doublon(c1, c1.tab[nombreListe1], nombreListe1) == false) {
			// Si les conditions sont respect�es, le programme �crit le mot � la position i dans
			// le conteneur c2.
			// Par cons�quent, les mots �crits dans le conteneur c2 ne sont que les mots d�sir�s.
			ecrire(c2, i, c1.tab[nombreListe1]);
			// incr�mentation du i, pour que le programme puisse �crire � la position suivante
			// la prochaine fois
			i++;
		}
	// incr�mentation de la variable nombreListe1, pour que le programme puisse lire le mot � la
	// position suivante
	nombreListe1++;
	}
	// tri du conteneur c, � partir de la position 0
	tri(c2, 0);
	// affiche le conteneur en entier, de la position 0 � la fin
	affiche(c2, 0, c2.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c1, car le programme est fini
	detruire(c1);
	// destruction du conteneur c2, car le programme est fini
	detruire(c2);
}