#include <stdio.h>
#include "braille.h"

int main(int argc, char const *argv[]) {
	char text[256];
	byte *b;
	int c, i;

	scanf("%[^\n]s", &text);
	for (c = 0; text[c]; c++)
	{
		b = bitsof(letter2code(text[c]));
		for (i = 0; i < 6; ++i)
			printf("%c", (b[i])? '*' : '.');
		printf("\n");
		free(b);
	}

	return 0;
}
