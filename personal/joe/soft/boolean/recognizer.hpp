#pragma once
#include <stdio.h>
#include "letter.hpp"

int max_in_array(float *array)
{
	int index = 0;
	float max_score = -1;

	for (int i = 0; i < 10; ++i)
	{
		if (array[i] > max_score) {
			index = i;
			max_score = array[i];
		}
	}

	return index;
}

Letter* letter_loadtemplates(void)
{
	Letter* letter = (Letter*) malloc(10 * sizeof(Letter));
	char path[256];

	for (int i = 0; i < 10; ++i)
	{
		letter[i] = Letter();
		sprintf(path, "templates/%d.txt", i);
		letter[i].load('0' + i, path);
	}

	return letter;
}

char letter_recognize(Letter *templates, const char *path)
{
	Letter to_recognize;
	float score[10];

	to_recognize.load(0, path);
	for (int i = 0; i < 10; ++i)
	{
		score[i] = templates[i].compare(to_recognize);
		printf("%d: %.3f\n", i, score[i]);
	}

	return templates[max_in_array(score)].get_id();
}
