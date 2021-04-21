/**
 * @file boogle.cpp
 * @brief Lance le sprint voulu en tapant son numéro dans l'invite de console.
 */

#include <iostream>
#include "sprint1.h"
#include "sprint2.h"
#include "sprint3.h"
#include "sprint4.h"
#include "sprint5.h"
#include "sprint6.h"

using namespace std;

int main() {
	int num;
	cin >> num;
	switch (num) {
	case 1:
		sprint1(); break; // correspond au main du premier programme
	case 2:
		sprint2(); break; // correspond au main du deuxième programme 
	case 3:
		sprint3(); break; // correspond au main du troisième programme 
	case 4:
		sprint4(); break; // correspond au main du quatrième programme 
	case 5:
		sprint5(); break; // correspond au main du cinquième programme 
	case 6:
		sprint6(); break; // correspond au main du sixième programme 
	}
}