#include <greyscale.h>

int main(int argc, char *argv[]) {
	GREYSCALE *greyscale = greyscale_load(argv[1]);

	greyscale_display(greyscale);
	free(greyscale);

	return 0;
}
