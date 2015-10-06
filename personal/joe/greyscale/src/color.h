#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} COLOR;

COLOR *color_new()
{
	COLOR *color = (COLOR*) malloc(sizeof(COLOR));
	color->red = color->blue = color->green = 0;
	return color;
}

COLOR *color_read(FILE *stream)
{
	COLOR *color = color_new();
	char from_file[3];

	fread(from_file, sizeof(char), 3, stream);
	color->red = from_file[0];
	color->green = from_file[1];
	color->blue = from_file[2];

	return color;
}

bool color_is_white(COLOR *color)
{
	if (color->red > 220 && color->green > 220 && color->blue > 220)
		return true;
	else
		return false;
}
