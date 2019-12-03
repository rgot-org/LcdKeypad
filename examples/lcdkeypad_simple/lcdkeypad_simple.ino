#include "LcdKeypad.h"
LcdKeypad lcd_keypad; // instanciation du shield lcd_keypad
// #define KEYPAD_V1
void setup() {
}
void loop()
{
	byte btn = lcd_keypad.getLastButton();  // lecture du dernier bouton presse	
	if (btn != lcd_keypad.btnNONE) // si un bouton a été pressé
	{
		lcd_keypad.clear();
		lcd_keypad.print(btn); // afficher la valeur associée au bouton
	}
}