#include "braille.h"

void setup()
{
	byte i, j;
	byte *a;
	byte h;

	Serial.begin(9600);
	for (i = 0; i < 13; ++i)
	{
		a = bitsof((byte) i);
		Serial.print(i);
		Serial.print(":");
		for (j = 0; j < 8; ++j)
			Serial.print((a[j])? 1 : 0);
		Serial.println();
	}

	h = (byte) 10;
	for (i = 0; i < 8; Serial.print(((h >> i) & 0x1)? 1 : 0), ++i);
	Serial.print("\n");
	for (i = 0; i < 8; Serial.print((((~h) >> i) & 0x1)? 1 : 0), ++i);
	Serial.print("\n");
	h = setdot(h, 5, 0x1);
	for (i = 0; i < 8; Serial.print(((h >> i) & 0x1)? 1 : 0), ++i);
	Serial.print("\n");
	h = setdot(h, 1, 0x0);
	for (i = 0; i < 8; Serial.print(((h >> i) & 0x1)? 1 : 0), ++i);
	Serial.print("\n");
}

void loop()
{

}
