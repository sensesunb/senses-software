#ifndef BRAILLE_H
#define BRAILLE_H
#include <stdlib.h>
#include "bit2letter.h"
#define braille byte
#define one (0x1)

braille setdot(braille b, byte c, byte v)
{
	return (v)? b | (one << c) : b & ~(one << c);
}

braille getdot(braille b, byte c)
{
	return (b >> c) & one;
}

byte* bitsof(braille c)
{
	byte *a = (byte*) malloc(sizeof(byte) * 8);
	byte i = 0;

	for (i = 0; i < 8; ++i)
		a[i] = getdot(c, i);

	return a;
}

#undef one
#endif
