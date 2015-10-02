#ifndef LETTER_H
#define LETTER_H 0
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

class Letter {
private:
	bool* process_line(const char*);
	int compare_slots(int, int, Letter);
	char id;
	bool **pattern;

public:
	Letter(void);
	
	void load(char, const char*);
	float compare(Letter);

	/* gets and sets */
	bool get_pattern(int, int);
	char get_id();
};

Letter::Letter() {
	return;
}

bool* Letter::process_line(const char* line)
{
	bool *result = (bool*) malloc(8 * sizeof(bool));

	for (int i = 0; i < 8; ++i)
		result[i] = (line[i] == '*');

	return result;
}

int Letter::compare_slots(int x, int y, Letter to_compare)
{
	int result = -1;
	int bx = x-1;
	int by = y-1;
	int ex = x+1;
	int ey = y+1;

	if (bx < 0) bx++;
	if (by < 0) by++;
	if (ex == 8) ex--;
	if (ey == 8) ey--;

	for (int i = bx; i <= ex && result <= 0; ++i)
		for (int j = by; j <= ey && result <= 0; ++j)
			if (to_compare.get_pattern(i, j) == true)
				result = 1;

	return result;
}

/*
* Public functions
*/
void Letter::load(char identifier, const char *path)
{
	std::fstream inlet;
	std::string line;

	pattern = (bool**) malloc(8 * sizeof(bool*));
	inlet.open(path, std::fstream::in);

	for (int i = 0; i < 8; ++i)
	{
		std::getline(inlet, line);
		pattern[i] = process_line(line.c_str());
	}

	id = identifier;
	inlet.close();
}

float Letter::compare(Letter to_compare)
{
	float score = 0;
	int no_points = 0;

	for (int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++)
			if (pattern[x][y] == true)
				score += compare_slots(x, y, to_compare),
				++no_points;

	return score/no_points;
}

bool Letter::get_pattern(int x, int y)
{
	return pattern[x][y];
}

char Letter::get_id()
{
	return id;
}

#endif
