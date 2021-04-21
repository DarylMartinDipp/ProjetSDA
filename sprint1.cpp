/**
 * @file sprint1.cpp
 * @brief Lire une liste de mots saisie au clavier et afficher
 * � l'�cran le nombre de points qu'elle repr�sente.
 */

#include <iostream>
#include <cassert>
#include "sprint1.h"

using namespace std;

int nbePts(Mot mot) {
	// pr�condition : longueur du mot comoris entre 1 et 30 inclus
	assert(strlen(mot) >= 1 && strlen(mot) <= 30);
	// initialisation de la variable longueurMot, qui va contenir le nombre de caract�res du mot entr�
	// gr�ce � la fonction strlen
	// c'est un unsigned int, car la longueur ne peut pas �tre n�gative
	unsigned int longueurMot = strlen(mot);
	// sert � renvoyer le bon nombre de points selon la variable longueurMot  
	if (longueurMot <= 2)
		// renvoie 0 si la longueur du mot est inf�rieure ou �gale � 2
		return 0;
	else if (longueurMot == 3 || longueurMot == 4)
		// renvoie 1 si la longueur du mot est �gale � 3 ou � 4
		return 1;
	else if (longueurMot == 5)
		// renvoie 2 si la longueur du mot est �gale � 5
		return 2;
	else if (longueurMot == 6)
		// renvoie 3 si la longueur du mot est �gale � 6
		return 3;
	else if (longueurMot == 7)
		// renvoie 5 si la longueur du mot est �gale � 7
		return 5;
	else if (longueurMot >= 8)
		// renvoie 11 si la longueur du mot est sup�rieure ou �gale � 2
		return 11;
}

unsigned int compteurPts() {
	// initialise une variable qui totalise le nombre de points de la liste
	// c'est un unsigned int car le nombre de points ne peut pas �tre n�gatif
	unsigned int points = 0;
	// initialise la variable mot de type Mot � 0
	Mot mot = { 0 };
	// Boucle servant � prendre la liste de mot en enti�re, se terminant par *
	// Je compare donc "*" au mot (gr�ce � strcmp), et si le mot est "*" alors le programme s'arr�te
	// Cette boucle enregistre donc le mot "*", vu que le cin figure avant l'appel de la fonction nbePts
	// "*" �tant compos� que d'un seul caract�re, il ne rapporte pas de point, donc cela n'est pas g�nant
	while (strcmp("*", mot) != 0) {
		// entr�e du mot � l'�cran
		cin >> mot;
		// incr�mentation du nombre de points total avec le nombre de points du mot, renvoy� par
		// la fonction nbePts
		points += nbePts(mot);
	}
	// Renvoie du nombre de points total � la fonction sprint1
	return points;
}

void sprint1() {
	// initialise une variable qui totalise le nombre de points de la liste
	// c'est un unsigned int car le nombre de points ne peut pas �tre n�gatif
	unsigned int pts = compteurPts();
	// affichage du nombre de points total
	cout << pts << endl;
}