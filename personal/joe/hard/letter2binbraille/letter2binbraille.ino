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
	for (byte c = 0; c < 6; c++)
		Serial.print((getdot(b, c))? '*' : '.');
	Serial.println();
}

void loop()
{
	write_braille(letter2code(get_letter()));
}
