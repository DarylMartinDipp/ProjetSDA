/**
 * @file sprint5.cpp
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * à l'écran la liste de tous les mots apparaissant dans au moins deux de ces listes.
 */

#include <iostream>
#include "sprint2.h"
#include "sprint3.h"
#include "sprint5.h"

using namespace std;

ConteneurTDE c5;
ConteneurTDE c6;
Debut deb;

void constructTabDebut(ConteneurTDE& c) {
	// Initialisation de la nbListe de la structure Debut à 0.
	deb.nbListe = 0;
	// Initialisation du tableau tab de la structure Debut à 0.
	deb.tab[50] = { 0 };

	// Initialisation de la variable i, qui va servir à savoir à quelle ligne de deb.tab le 
	// programme doit écrire la valeur rendue par ecritListe, c'est à dire le rang de début
	// de la liste écrite.
	// Elle est initialisée à 1 et non à 0 car deb.tab[0] contient déjà la valeur 0, et ne doit
	// donc pas être écrasée.
	// C'est un unsigned int car il ne peut pas contenir de valeur négative.
	unsigned int i = 1;
	// Initialisation de la variable nbe à 0, un unsigned int.
	// Cette valeur, qui va être envoyé en paramètre à ecritListe, va permettre au programme
	// de connaître les lignes déjà écrites.  
	unsigned int nbe = 0;

	// Cette boucle est une boucle infinie. Le programme ne va sortir que
	// lorsque deb.tab[i] = deb.tab[i - 1], c'est à dire lorsque la valeur de début n'aura pas changé
	// d'une ligne à l'autre, c'est à dire lorsque l'utilisateur aura rempli une liste vide.
	while (0 == 0) {
		// Lancement de la procédure ecritListe.
		// La valeur renvoyée par ecritListe, qui va s'additionner à nbe, va être stocké dans 
		// deb.tab, au rang i : c'est le rang du dernier mot de la liste entrée.
		deb.tab[i] = ecritListe(c, nbe);
		// copie de la valeur de deb.tab[i] dans nbe, pour la boucle suivante
		nbe = deb.tab[i];
		// Cette condition va permettre au programme de s'arrêter.
		// Le programme ne va sortir que lorsque deb.tab[i] = deb.tab[i - 1],
		// c'est à dire lorsque la valeur de début n'aura pas changé d'une ligne à l'autre,
		// c'est à dire lorsque l'utilisateur aura rempli une liste vide.
		if (deb.tab[i] == deb.tab[i - 1]) {
			// Mise de la dernière ligne à 0, car elle ne doit pas garder la même valeur que la
			// précédente une fois que la condition est validée.
			deb.tab[i] = 0;
			// break permettant la sortie de la boucle.
			break;
		}
		// incrémentation du i, pour que le programme puisse écrire à la position suivante
		// la prochaine fois
		i++;
		// incrémentation de deb.nbListe, pour que cette valeur contienne bien le bon nombre de liste
		deb.nbListe++;
	}

	/*

	Ceci est l'affichage de la structure que j'avais codé afin d'essayer de débugger
	mon programme.
	Je l'ai laissé si cela peut aider la compréhension de la structure Debut.

	-----------------------------------------------------------------------------------------------

	for (unsigned int k = 0; k < 50; k++) {
		cout << k << " " << deb.tab[k] << endl;
	}

	cout << "nbe : " << deb.nbListe << endl;

	system("PAUSE");

	affiche(c5, 0, c5.capacite);*/
}

void sprint5() {
	// initialisation du conteneur c5, de capacité 1 et de pas d'extension 1
	initialiser(c5, 1, 1);
	// initialisation du conteneur c6, de capacité 1 et de pas d'extension 1
	initialiser(c6, 1, 1);
	// Lancement de la procédure constructTabDebut, afin de remplir la structure Debut, mais aussi
	// remplir le conteneur c5 avec tous les mots.
	constructTabDebut(c5);

	// Initialisation de la variable a à 0, un unsigned int car il ne va jamais être négatif.
	// Cette variable correspond à la ligne à laquelle le programme va écrire le mot dans le
	// conteneur c6.
	unsigned int a = 0;

	// Cette boucle de 4 "for" imbriqués va permettre de savoir si un mot est présent dans plusieurs
	// listes.
	// Le mot va donc être comparé à tous les mots des listes SUIVANTES, jusqu'à changer au mot
	// suivant. 

	// Ce premier "for" va donner au programme la liste dans lequel le mot à comparer aux autres se 
	// trouve. Le i va donc parcourir les listes, de 0 jusqu'à deb.nbListe - 1, car cela ne sert
	// à rien de comparer la dernière liste avec elle même.
	for (unsigned int i = 0; i < deb.nbListe - 1; i++) {
		// Ce deuxième "for" va donner au programme le nombre maximum de mot dans la liste donnée
		// par le for précédent, pour les parcourir.
		// Le deb.tab[i] donne le début, et deb.tab[i + 1] donne la fin.
		for (unsigned int j = deb.tab[i]; j < deb.tab[i + 1]; j++) {
			// Ce troisième "for" va donner au programme la liste dans lequel le mot qui est 
			// comparé se trouve. Le k va donc de i + 1, soit 1 liste après le i, jusqu'à
			// deb.nbListe, pour avoir la dernière liste.
			for (unsigned int k = i + 1; k < deb.nbListe; k++) {
				// Ce quatrième "for" va donner au programme le nombre maximum de mot dans la liste
				// donnée par le for précédent, pour les parcourir.
				for (unsigned int m = deb.tab[k]; m < deb.tab[k + 1]; m++) {
					// Cette condition permet de savoir si les deux mots comparés, aux rangs j et m,
					// sont bien les mêmes, grâce à strcmp.
					// De plus, on vérifie s'ils ont déjà été entrés, grâce à la fonction doublon.

					/* Cet affichage sert à savoir quels mots sont comparés, pour m'aider à la
					 * programmation.
					 * ----------------------------------------------------------------------------
					cout << "mot 1 : " << c5.tab[j] << endl;
					cout << "mot 2 : " << c5.tab[m] << endl;
					system("PAUSE");
					-------------------------------------------------------------------------------
					*/

					if (strcmp(c5.tab[j], c5.tab[m]) == 0 && doublon(c6, c5.tab[j], c6.capacite) == false) {
						// Si la condition est respectée, on écrit le mot dans le conteneur c6
						ecrire(c6, a, c5.tab[j]);
						// incrémentation du a, pour que le programme puisse écrire à la position
						//suivante la prochaine fois
						a++;
					}
				}
			}
		}
	}
	// tri du conteneur c6, à partir de la position 0
	tri(c6, 0);
	// affiche le conteneur en entier, de la position 0 à la fin
	affiche(c6, 0, c6.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c5, car le programme est fini
	detruire(c5);
	// destruction du conteneur c6, car le programme est fini
	detruire(c6);
}