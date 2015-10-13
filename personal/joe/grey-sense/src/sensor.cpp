#include <iostream>
#include <vector>
#include <letter.hpp>
#include <sensor.hpp>
#include <bitmap.h>

void show(Letter letter, std::vector<int*> found)
{
	std::vector<int*>::iterator it;

	std::cout << letter.get_id() << ":\n";
	for (it = found.begin(); it != found.end(); ++it)
		std::cout << "- [" << (*it)[0] << ", " << (*it)[1] << "] @ " << (*it)[2] << "%\n";
}

int main(int argc, char *argv[]) {
	Sensor sensor;
	std::vector<Letter> templates;
	BITMAP *bitmap = NULL;
	std::vector<Letter>::iterator it;
	std::vector<int*> found;

	sensor.load("templates/std");
	templates = sensor.get_templates();
	bitmap = bitmap_load(argv[1]);
	for (it = templates.begin(); it != templates.end(); ++it)
	{
		found = sensor.find(bitmap, *it);
		if (found.size() > 0) show(*it, found);
	}

	return 0;
}
