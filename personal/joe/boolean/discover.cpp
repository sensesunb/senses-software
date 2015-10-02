#include <cstdio>
#include "recognizer.hpp"

int main(int argc, char const *argv[]) {
	printf("%c\n", letter_recognize(letter_loadtemplates(), argv[1]));
	return 0;
}
