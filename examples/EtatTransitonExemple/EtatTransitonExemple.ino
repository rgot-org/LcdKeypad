#include "LcdKeypad.h"

// instanciation du shield lcd_keypad
LcdKeypad lcd_keypad;
// enumeration des differents etats
enum enum_etats
{
	ETAT_ACCUEIL,
	ETAT_REGLAGE, 
	ETAT_REPOS
};
#define KEYPAD_V1
void setup(){	
}

void loop()
{
	// declaration de l'etat et du bouton
	// les variables sont declarees static de ce fait elles ne sont pas effacees a chaque rebouclage
	static byte etat = ETAT_ACCUEIL , btn= lcd_keypad.btnNONE; 

	btn = lcd_keypad.getLastButton();  // lecture du fernier bouton presse
	// etude de cas
	switch (etat)
	{
	case ETAT_REPOS:
		// si on appuie sur le bouton RIGHT on passera à l'etat REGLAGE au prochain rebouclage
		if (btn == lcd_keypad.btnRIGHT) etat = ETAT_REGLAGE;
		if (btn == lcd_keypad.btnLEFT) etat = ETAT_ACCUEIL;
		break;
	case ETAT_ACCUEIL:
		// partie "do / afficher Accueil
		lcd_keypad.clear();
		lcd_keypad.print("ACCUEIL");
		etat = ETAT_REPOS;
		break;
	case ETAT_REGLAGE:
		lcd_keypad.clear();
		lcd_keypad.print("REGLAGE");
		etat = ETAT_REPOS;
		break;
	}
}