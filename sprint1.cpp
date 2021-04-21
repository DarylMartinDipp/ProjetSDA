/**
 * @file sprint1.cpp
 * @brief Lire une liste de mots saisie au clavier et afficher
 * à l'écran le nombre de points qu'elle représente.
 */

#include <iostream>
#include <cassert>
#include "sprint1.h"

using namespace std;

int nbePts(Mot mot) {
	// précondition : longueur du mot comoris entre 1 et 30 inclus
	assert(strlen(mot) >= 1 && strlen(mot) <= 30);
	// initialisation de la variable longueurMot, qui va contenir le nombre de caractères du mot entré
	// grâce à la fonction strlen
	// c'est un unsigned int, car la longueur ne peut pas être négative
	unsigned int longueurMot = strlen(mot);
	// sert à renvoyer le bon nombre de points selon la variable longueurMot  
	if (longueurMot <= 2)
		// renvoie 0 si la longueur du mot est inférieure ou égale à 2
		return 0;
	else if (longueurMot == 3 || longueurMot == 4)
		// renvoie 1 si la longueur du mot est égale à 3 ou à 4
		return 1;
	else if (longueurMot == 5)
		// renvoie 2 si la longueur du mot est égale à 5
		return 2;
	else if (longueurMot == 6)
		// renvoie 3 si la longueur du mot est égale à 6
		return 3;
	else if (longueurMot == 7)
		// renvoie 5 si la longueur du mot est égale à 7
		return 5;
	else if (longueurMot >= 8)
		// renvoie 11 si la longueur du mot est supérieure ou égale à 2
		return 11;
}

unsigned int compteurPts() {
	// initialise une variable qui totalise le nombre de points de la liste
	// c'est un unsigned int car le nombre de points ne peut pas être négatif
	unsigned int points = 0;
	// initialise la variable mot de type Mot à 0
	Mot mot = { 0 };
	// Boucle servant à prendre la liste de mot en entière, se terminant par *
	// Je compare donc "*" au mot (grâce à strcmp), et si le mot est "*" alors le programme s'arrête
	// Cette boucle enregistre donc le mot "*", vu que le cin figure avant l'appel de la fonction nbePts
	// "*" étant composé que d'un seul caractère, il ne rapporte pas de point, donc cela n'est pas gênant
	while (strcmp("*", mot) != 0) {
		// entrée du mot à l'écran
		cin >> mot;
		// incrémentation du nombre de points total avec le nombre de points du mot, renvoyé par
		// la fonction nbePts
		points += nbePts(mot);
	}
	// Renvoie du nombre de points total à la fonction sprint1
	return points;
}

void sprint1() {
	// initialise une variable qui totalise le nombre de points de la liste
	// c'est un unsigned int car le nombre de points ne peut pas être négatif
	unsigned int pts = compteurPts();
	// affichage du nombre de points total
	cout << pts << endl;
}