#include <color.h>
#include <bitmap.h>
#include <letter.hpp>

class Cropper {
public:
	Cropper(void);
	bool** crop(BITMAP*, int, int, int, int);
};

/* PRIVATE FUNCTIONS */

/* PUBLIC FUNCTIONS */

Cropper::Cropper(void)
{
	return;
}
bool** Cropper::crop(BITMAP *bmp, int bx, int by, int ex, int ey)
{
	int dy = ey-by;
	int dx = ex-bx;
	bool **portion = (bool**) malloc(dy * sizeof(bool*));

	for (int y = 0; y < dy; ++y)
	{
		portion[y] = (bool*) malloc(dx * sizeof(bool));
		for (int x = 0; x < dx; ++x)
		{
			portion[y][x] = (color_is_white(&bmp->table[by+y][bx+x]))? false : true;
		}
	}

	return portion;
}
