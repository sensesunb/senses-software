#include <iostream>
#include <vector>
#include <bitmap.h>
#include <sensor.hpp>

void show_results(std::vector<float*> found)
{
	for (int i = 0; i < found.size(); ++i)
	{
		std::cout << "- " << (char) found[i][0] << " @ ";
		std::cout << (int) found[i][2] << "x" << (int) found[i][3];
		std::cout << std::endl;
	}
}

int main(int argc, char *argv[]) {
	Sensor input_font;
	Sensor processing_font;
	std::vector<float*> found;
	BITMAP *bitmap;

	input_font.load("templates/Input");
	processing_font.load("templates/Processing");
	bitmap = bitmap_load(argv[1]);

	std::cout << "--- # Input" << std::endl;
	found = input_font.identify(bitmap);
	if (found.size() > 0)
		show_results(found);
	std::cout << std::endl;

	std::cout << "--- # Processing" << std::endl;
	found = processing_font.identify(bitmap);
	if (found.size() > 0)
		show_results(found);

	std::cout << "..." << std::endl;

	return 0;
}
