#include <stdio.h>
#include <letter.hpp>
#include <comparator.hpp>

int main(int argc, char *argv[]) {
	Comparator comparator;
	Letter to_find = comparator.greyscale2letter(greyscale_load(argv[1]));
	printf("%c\n", comparator.identify(to_find, true));
	return 0;
}
