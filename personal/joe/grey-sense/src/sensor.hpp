#pragma once
#include <vector>
#include <cstdio>
#include <bitmap.h>
#include <letter.hpp>
#include <comparator.hpp>
#include <cropper.hpp>
#include <greyscale.h>
#define SIMILARITY (0.9)

class Sensor {
	float *identify_portion(Letter);
	std::string typeface;
	Comparator comparator;
public:
	Sensor(void);
	void load(std::string);
	void display(void);
	std::vector<Letter> get_templates();
	Letter get_letter(char);
	/* std::string sense(char*) */ // this function will extract the fucking text
	std::vector<int*> find(BITMAP*, Letter);
	std::vector<float*> identify(BITMAP*);
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

void Sensor::load(std::string src = "templates/std")
{
	typeface = src;
	comparator.load_templates(src);
}

void Sensor::display()
{
	std::vector<Letter> templates = comparator.get_templates();
	std::vector<Letter>::iterator it;

	for (it = templates.begin(); it != templates.end(); ++it)
	{
		printf("---\n");
		(*it).write();
	}
}

std::vector<Letter> Sensor::get_templates()
{
	return comparator.get_templates();
}

Letter Sensor::get_letter(char to_find)
{
	Letter result;
	std::vector<Letter> templates = comparator.get_templates();
	std::vector<Letter>::iterator it;

	for (it = templates.begin(); it != templates.end(); ++it)
	{
		if ((*it).get_id() == to_find) {
			result = *it;
			break;
		}
	}

	return result;
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
			result = letter.compare(portion);
			// printf("%d %d: %.2f", y, x, result);

			if (result > SIMILARITY) {
				// printf("\tfound!");
				vec = (int*) malloc(5 * sizeof(int));
				vec[0] = x;
				vec[1] = y;
				vec[2] = (int) 100 * result;
				found.push_back(vec);
			}

			// printf("\n");
			portion.clean();
		}
	}

	return found;
}

float* Sensor::identify_portion(Letter portion)
{
	std::vector<Letter> templates = comparator.get_templates();
	Letter letter;
	float max_result = 0;
	float result = 0;
	int index = 0;
	float *found = NULL;

	for (int i = 0; i < templates.size(); ++i)
	{
		letter = templates.at(i);
		result = letter.compare(portion);
		if (max_result < result) {
			index = i;
			max_result = result;
		}
	}

	if (max_result > SIMILARITY) {
		found = (float*) malloc(5 * sizeof(float));
		found[0] = '0' + index;
		found[1] = 100 * result;
	}

	return found;
}

std::vector<float*> Sensor::identify(BITMAP *image)
{
	Cropper cropper;
	Letter portion;
	std::vector<float*> found;
	float *result;
	int bx = 0;
	int by = 0;
	int ex = image->width - 32;
	int ey = image->height - 32;
	int sx = 3;
	int sy = 3;
	int h = 32+1;

	if (image->width == 32 && image->height == 32) {
		portion = comparator.greyscale2letter(greyscale_from_bitmap(image));
		result = (float*) malloc(sizeof(float)*5);
		result[0] = comparator.identify(portion);
		result[1] = -1;
		result[2] = result[3] = 0;
		found.push_back(result);
	}
	else for (int y = by; y < ey; y += sy)
	{
		for (int x = bx; x < ex; x += sx)
		{
			portion.set_pattern(cropper.crop(image, x, y, x+h, y+h));
			result = identify_portion(portion);
			if (result != NULL) {
				result[2] = x;
				result[3] = y;
				found.push_back(result);
			}
			portion.clean();
		}
	}

	return found;
}

#undef SIMILARITY
