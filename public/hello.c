#include <stdio.h>

const char yo[] = "hi :)";

int main(int argc, char const *argv[])
{
	if (argc <= 5) {
		printf("%c", yo[argc-1]);
		return main(argc+1, argv);
	}
	else {
		printf("\n");
		return 0;
	}
}
