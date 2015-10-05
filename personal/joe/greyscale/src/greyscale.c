#include "greyscale.h"

int main(int argc, char *argv[]) {
	GREYSCALE *greyscale = greyscale_load(argv[1]);

	bitmap_write(bitmap);
	bitmap_display(bitmap);
	free(bitmap);

	return 0;
}
