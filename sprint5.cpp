/**
 * @file sprint5.cpp
 * @brief Lire deux listes de mots saisies au clavier et afficher
 * � l'�cran la liste de tous les mots apparaissant dans au moins deux de ces listes.
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
	// Initialisation de la nbListe de la structure Debut � 0.
	deb.nbListe = 0;
	// Initialisation du tableau tab de la structure Debut � 0.
	deb.tab[50] = { 0 };

	// Initialisation de la variable i, qui va servir � savoir � quelle ligne de deb.tab le 
	// programme doit �crire la valeur rendue par ecritListe, c'est � dire le rang de d�but
	// de la liste �crite.
	// Elle est initialis�e � 1 et non � 0 car deb.tab[0] contient d�j� la valeur 0, et ne doit
	// donc pas �tre �cras�e.
	// C'est un unsigned int car il ne peut pas contenir de valeur n�gative.
	unsigned int i = 1;
	// Initialisation de la variable nbe � 0, un unsigned int.
	// Cette valeur, qui va �tre envoy� en param�tre � ecritListe, va permettre au programme
	// de conna�tre les lignes d�j� �crites.  
	unsigned int nbe = 0;

	// Cette boucle est une boucle infinie. Le programme ne va sortir que
	// lorsque deb.tab[i] = deb.tab[i - 1], c'est � dire lorsque la valeur de d�but n'aura pas chang�
	// d'une ligne � l'autre, c'est � dire lorsque l'utilisateur aura rempli une liste vide.
	while (0 == 0) {
		// Lancement de la proc�dure ecritListe.
		// La valeur renvoy�e par ecritListe, qui va s'additionner � nbe, va �tre stock� dans 
		// deb.tab, au rang i : c'est le rang du dernier mot de la liste entr�e.
		deb.tab[i] = ecritListe(c, nbe);
		// copie de la valeur de deb.tab[i] dans nbe, pour la boucle suivante
		nbe = deb.tab[i];
		// Cette condition va permettre au programme de s'arr�ter.
		// Le programme ne va sortir que lorsque deb.tab[i] = deb.tab[i - 1],
		// c'est � dire lorsque la valeur de d�but n'aura pas chang� d'une ligne � l'autre,
		// c'est � dire lorsque l'utilisateur aura rempli une liste vide.
		if (deb.tab[i] == deb.tab[i - 1]) {
			// Mise de la derni�re ligne � 0, car elle ne doit pas garder la m�me valeur que la
			// pr�c�dente une fois que la condition est valid�e.
			deb.tab[i] = 0;
			// break permettant la sortie de la boucle.
			break;
		}
		// incr�mentation du i, pour que le programme puisse �crire � la position suivante
		// la prochaine fois
		i++;
		// incr�mentation de deb.nbListe, pour que cette valeur contienne bien le bon nombre de liste
		deb.nbListe++;
	}

	/*

	Ceci est l'affichage de la structure que j'avais cod� afin d'essayer de d�bugger
	mon programme.
	Je l'ai laiss� si cela peut aider la compr�hension de la structure Debut.

	-----------------------------------------------------------------------------------------------

	for (unsigned int k = 0; k < 50; k++) {
		cout << k << " " << deb.tab[k] << endl;
	}

	cout << "nbe : " << deb.nbListe << endl;

	system("PAUSE");

	affiche(c5, 0, c5.capacite);*/
}

void sprint5() {
	// initialisation du conteneur c5, de capacit� 1 et de pas d'extension 1
	initialiser(c5, 1, 1);
	// initialisation du conteneur c6, de capacit� 1 et de pas d'extension 1
	initialiser(c6, 1, 1);
	// Lancement de la proc�dure constructTabDebut, afin de remplir la structure Debut, mais aussi
	// remplir le conteneur c5 avec tous les mots.
	constructTabDebut(c5);

	// Initialisation de la variable a � 0, un unsigned int car il ne va jamais �tre n�gatif.
	// Cette variable correspond � la ligne � laquelle le programme va �crire le mot dans le
	// conteneur c6.
	unsigned int a = 0;

	// Cette boucle de 4 "for" imbriqu�s va permettre de savoir si un mot est pr�sent dans plusieurs
	// listes.
	// Le mot va donc �tre compar� � tous les mots des listes SUIVANTES, jusqu'� changer au mot
	// suivant. 

	// Ce premier "for" va donner au programme la liste dans lequel le mot � comparer aux autres se 
	// trouve. Le i va donc parcourir les listes, de 0 jusqu'� deb.nbListe - 1, car cela ne sert
	// � rien de comparer la derni�re liste avec elle m�me.
	for (unsigned int i = 0; i < deb.nbListe - 1; i++) {
		// Ce deuxi�me "for" va donner au programme le nombre maximum de mot dans la liste donn�e
		// par le for pr�c�dent, pour les parcourir.
		// Le deb.tab[i] donne le d�but, et deb.tab[i + 1] donne la fin.
		for (unsigned int j = deb.tab[i]; j < deb.tab[i + 1]; j++) {
			// Ce troisi�me "for" va donner au programme la liste dans lequel le mot qui est 
			// compar� se trouve. Le k va donc de i + 1, soit 1 liste apr�s le i, jusqu'�
			// deb.nbListe, pour avoir la derni�re liste.
			for (unsigned int k = i + 1; k < deb.nbListe; k++) {
				// Ce quatri�me "for" va donner au programme le nombre maximum de mot dans la liste
				// donn�e par le for pr�c�dent, pour les parcourir.
				for (unsigned int m = deb.tab[k]; m < deb.tab[k + 1]; m++) {
					// Cette condition permet de savoir si les deux mots compar�s, aux rangs j et m,
					// sont bien les m�mes, gr�ce � strcmp.
					// De plus, on v�rifie s'ils ont d�j� �t� entr�s, gr�ce � la fonction doublon.

					/* Cet affichage sert � savoir quels mots sont compar�s, pour m'aider � la
					 * programmation.
					 * ----------------------------------------------------------------------------
					cout << "mot 1 : " << c5.tab[j] << endl;
					cout << "mot 2 : " << c5.tab[m] << endl;
					system("PAUSE");
					-------------------------------------------------------------------------------
					*/

					if (strcmp(c5.tab[j], c5.tab[m]) == 0 && doublon(c6, c5.tab[j], c6.capacite) == false) {
						// Si la condition est respect�e, on �crit le mot dans le conteneur c6
						ecrire(c6, a, c5.tab[j]);
						// incr�mentation du a, pour que le programme puisse �crire � la position
						//suivante la prochaine fois
						a++;
					}
				}
			}
		}
	}
	// tri du conteneur c6, � partir de la position 0
	tri(c6, 0);
	// affiche le conteneur en entier, de la position 0 � la fin
	affiche(c6, 0, c6.capacite);
	// affiche ensuite le symbole "*" pour respecter le out
	cout << "*" << endl;
	// destruction du conteneur c5, car le programme est fini
	detruire(c5);
	// destruction du conteneur c6, car le programme est fini
	detruire(c6);
}