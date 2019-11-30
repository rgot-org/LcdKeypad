// 
// 
// 

#include "LcdKeypad.h"

LcdKeypad::LcdKeypad() : LiquidCrystal(8, 9, 4, 5, 6, 7) {
	LiquidCrystal::begin(16, 2);              // start the library
}
int LcdKeypad::readButton()
{
	int adc_key_in = analogRead(0);     // read the value from the sensor 		
#ifdef KEYPAD_V1
	if (adc_key_in < 100)  return btnRIGHT;
	if (adc_key_in < 200)  return btnUP;
	if (adc_key_in < 400)  return btnDOWN;
	if (adc_key_in < 550)  return btnLEFT;
	if (adc_key_in < 800)  return btnSELECT;
#else
	if (adc_key_in < 50)   return btnRIGHT;
	if (adc_key_in < 250)  return btnUP;
	if (adc_key_in < 450)  return btnDOWN;
	if (adc_key_in < 650)  return btnLEFT;
	if (adc_key_in < 850)  return btnSELECT;
#endif // KEYPAD_V1

	return btnNONE;  // when all others fail, return this...
}
int LcdKeypad::getLastButton() {
	static int etatBtn = 0;
	int btn = readButton();
	if (btn != btnNONE)
	{
		etatBtn = btn;
	}
	else {
		if (etatBtn != btnNONE) {
			int etat = etatBtn;
			etatBtn = btnNONE;
			return etat;
		}
	}
	return btnNONE;
}

LcdKeypad LcdKp;

