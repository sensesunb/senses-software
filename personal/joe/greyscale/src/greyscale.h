#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "color.h"
#include "bitmap.h"

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
			gs->table[j][i] = (color_is_white(bm->table[j][i]))? false : true;
		}
	}
}

GS* greyscale_load()
{
	
}

void greyscale_display(GS* gs)
{
	int i, j;

	for (j = gs->height - 1; j >= 0; --j)
	{
		for (i = 0; i < gs->width; ++i)
		{
			printf("%c", (gs->table[j][i])? '#' : ' ');
		}
		printf("\n");
	}
}

#undef GS
