#include "LcdKeypad.h"
LcdKeypad lcd_keypad; // instanciation du shield lcd_keypad
//#define KEYPAD_V1
void setup() {
}
void loop()
{
	byte btn = lcd_keypad.getLastButton();  // lecture du dernier bouton presse	
	if (btn != lcd_keypad.btnNONE) // si un bouton a été pressé
	{
		lcd_keypad.clear();
		switch (btn)
		{
		case lcd_keypad.btnRIGHT :
			lcd_keypad.print("RIGHT");
			break;
		case lcd_keypad.btnLEFT:
			lcd_keypad.print("LEFT");
			break;
		default:
			lcd_keypad.print("AUTRE BOUTON");
			break;
		}
	}
}