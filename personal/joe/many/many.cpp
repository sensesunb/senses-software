#include <iostream>
#include <vector>
#include <bitmap.h>
#include <letter.hpp>
#include <sensor.hpp>

int main(int argc, char *argv[]) {
	Sensor input_font;
	Sensor processing_font;
	std::vector<int*> input_found;
	std::vector<int*> processing_found;
	BITMAP *bitmap;

	input_font.load("templates/Input");
	processing_font.load("templates/Processing");
	bitmap = bitmap_load(argv[1]);

	for (char c = '0'; c <= '9'; c++)
	{
		input_found = input_font.find(bitmap, input_font.get_letter(c));
		processing_found = processing_font.find(bitmap, processing_font.get_letter(c));
		std::cout << c;
		if (input_found.size() > 0) std::cout << "\tinput";
		if (processing_found.size() > 0) std::cout << "\tprocessing";
		std::cout << std::endl;
	}

	return 0;
}
