#include <color.h>
#include <bitmap.h>
#include <letter.hpp>

class Cropper {
public:
	Cropper(void);
	Letter crop(BITMAP*, int, int, int, int);
};

/* PRIVATE FUNCTIONS */

/* PUBLIC FUNCTIONS */

Cropper::Cropper(void)
{
	return;
}
Letter Cropper::crop(BITMAP *bmp, int bx, int by, int ex, int ey)
{
	Letter cropped;
	bool **portion = (bool**) malloc((ey-by) * sizeof(bool*));

	for (int y = 0; y < ey; ++y)
	{
		portion[y] = (bool*) malloc((ex-bx) * sizeof(bool));
		for (int x = 0; x < ex; ++x)
		{
			portion[y][x] = (color_is_white(&bmp->table[y][x]))? false : true;
		}
	}

	cropped.set_pattern(portion);
	return cropped;
}
