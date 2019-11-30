#ifndef _LCDKEYPAD_h
#define _LCDKEYPAD_h

#include <LiquidCrystal.h>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class LcdKeypad : public LiquidCrystal
{
 public:
	 LcdKeypad();
	 int readButton();	
	 int getLastButton();
	 enum btnState
	 {
		 btnRIGHT = 0,
		 btnUP,
		 btnDOWN,
		 btnLEFT,
		 btnSELECT,
		 btnNONE
	 };
};

extern LcdKeypad LcdKp;

#endif

