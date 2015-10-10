#pragma once
#include <vector>
#include <cstdio>
#include <bitmap.h>
#include <letter.hpp>
#include <comparator.hpp>
#include <cropper.hpp>
#define SIMILARITY (0.618034)

class Sensor {
	Comparator comparator;
public:
	Sensor(void);
	std::vector<Letter> get_templates();
	/* std::string sense(char*) */ // this function will extract the fucking text
	std::vector<int*> find(BITMAP*, Letter);

};

/************************
*	PRIVATE FUNCTIONS	*
************************/

/************************
*	PUBLIC FUNCTIONS	*
************************/

Sensor::Sensor(void)
{
	return;
}

std::vector<Letter> Sensor::get_templates()
{
	return comparator.get_templates();
}

/*
std::string Sensor::sense(char *path)
{
	std::string text;

	return text;
}
*/

std::vector<int*> Sensor::find(BITMAP* image, Letter letter)
{
	Cropper cropper;
	Letter portion;
	std::vector<int*> found;
	int bx = 0;
	int by = 0;
	int ex = image->width - letter.get_side();
	int ey = image->height - letter.get_side();
	int sx = 1;
	int sy = 1;
	int h = letter.get_side()+1;
	int* vec;
	float result;

	// printf("--- # %c\n", letter.get_id());
	// printf("[%d %d] -> [%d %d] : [%d %d]\n", by, bx, ey, ex, sy, sx);
	// bitmap_display(image);

	for (int y = by; y < ey; y += sy)
	{
		for (int x = bx; x < ex; x += sx)
		{
			portion.set_pattern(cropper.crop(image, x, y, x+h, y+h));
			result = portion.compare(letter);
			// printf("%d %d: %.2f", y, x, result);

			if (result > SIMILARITY) {
				// printf("\tfound!");
				vec = (int*) malloc(2 * sizeof(int));
				vec[0] = y;
				vec[1] = x;
				found.push_back(vec);
			}

			// printf("\n");
			portion.clean();
		}
	}

	return found;
}

#undef SIMILARITY
