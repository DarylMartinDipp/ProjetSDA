/**
 * @file boogle.cpp
 * @brief Lance le sprint voulu en tapant son num�ro dans l'invite de console.
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
		sprint2(); break; // correspond au main du deuxi�me programme 
	case 3:
		sprint3(); break; // correspond au main du troisi�me programme 
	case 4:
		sprint4(); break; // correspond au main du quatri�me programme 
	case 5:
		sprint5(); break; // correspond au main du cinqui�me programme 
	case 6:
		sprint6(); break; // correspond au main du sixi�me programme 
	}
}