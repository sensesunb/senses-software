#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <color.h>
#include <bitmap.h>

typedef struct {
	int width;
	int height;
	bool **table;
} GREYSCALE;

#define GS GREYSCALE

GS* greyscale_new()
{
	GS *gs = (GS*) malloc(sizeof(GS));
	return gs;
}

GS* greyscale_from_bitmap(BITMAP *bm)
{
	GS *gs = greyscale_new();
	int i, j;

	gs->height = bm->height;
	gs->width = bm->width;

	gs->table = (bool**) malloc(gs->height * sizeof(bool*));
	for (j = 0; j < gs->height; ++j)
	{
		gs->table[j] = (bool*) malloc(gs->width * sizeof(bool));
		for (i = 0; i < gs->width; ++i)
		{
			/* pay attention to this convention! */
			gs->table[j][i] = (color_is_white(&bm->table[j][i]))? false : true;
		}
	}

	return gs;
}

GS* greyscale_load(char *path)
{
	return greyscale_from_bitmap(bitmap_load(path));
}

void greyscale_display(GS* gs)
{
	int i, j;

	printf("---\n");
	for (j = 0; j < gs->height; ++j)
	{
		for (i = 0; i < gs->width; ++i)
		{
			printf("%c", (gs->table[j][i])? '#' : ' ');
		}
		printf("|\n");
	}
}

/*
int greyscale_compare_slots(int x, int y, GS *to_compare)
{
	int result = -1;
	int bx = x-1;
	int by = y-1;
	int ex = x+1;
	int ey = y+1;
	int i, j;

	if (bx < 0) bx++;
	if (by < 0) by++;
	if (ex == to_compare->width) ex--;
	if (ey == to_compare->height) ey--;

	for (i = bx; i <= ex && result <= 0; ++i)
		for (j = by; j <= ey && result <= 0; ++j)
			if (to_compare->table[i][j] == true)
				result = 1;

	return result;
}

float greyscale_compare(GS *template, GS *to_compare)
{
	float score = 0;
	int no_points = 0;
	int x, y;

	if (template->height != to_compare->height || template->width != to_compare->width) {
		return -1;
	}

	for (x = 0; x < 8; ++x)
		for (y = 0; y < 8; ++y)
			if (template->table[x][y] == true)
				score += greyscale_compare_slots(x, y, to_compare),
				++no_points;

	return score/no_points;
}
*/

#undef GS
