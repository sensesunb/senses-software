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

#undef GS
