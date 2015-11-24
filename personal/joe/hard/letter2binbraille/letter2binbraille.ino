#include "letter2braille.h"

void setup()
{
	Serial.begin(9600);
}

char get_letter()
{
	char junk;
	char data;

	while (!Serial.available())
		;
	data = Serial.read();
	while (Serial.available())
	{
		junk = Serial.read();
	}

	return data;
}

void write_braille(byte b)
{
	for (byte i = 0; i < 6; ++i)
		Serial.print(((b >> i) & 0x1)? '*' : '.');
	Serial.println();
}

void loop()
{
	write_braille(letter2code(get_letter()));
}
