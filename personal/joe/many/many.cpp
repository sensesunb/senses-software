#include <iostream>
#include <vector>
#include <bitmap.h>
#include <sensor.hpp>

int main(int argc, char *argv[]) {
	Sensor input_font;
	Sensor processing_font;
	// std::vector<int*> input_found;
	// std::vector<int*> processing_found;
	BITMAP *bitmap;

	input_font.load("templates/Input");
	processing_font.load("templates/Processing");
	bitmap = bitmap_load(argv[1]);

	for (char c = '0'; c <= '9'; c++)
	{
		std::cout << c;
		if (input_font.find(bitmap, input_font.get_letter(c)).size() > 0) std::cout << " input";
		if (processing_font.find(bitmap, processing_font.get_letter(c)).size() > 0) std::cout << " processing";
		std::cout << std::endl;
	}

	return 0;
}
