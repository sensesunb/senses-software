#ifndef LETTER_H
#define LETTER_H 0
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 32

class Letter {
private:
	bool* process_line(const char*);
	int compare_slots(int, int, Letter);
	int side;
	char id;
	bool **pattern;

public:
	Letter(void);

	void load(char, const char*);
	void write();
	float compare(Letter);

	/* gets and sets */
	int get_side();
	bool get_pattern(int, int);
	char get_id();
	void set_id(char);
	void set_pattern(bool**);
};

Letter::Letter() {
	side = SIZE;
	return;
}

bool* Letter::process_line(const char* line)
{
	bool *result = (bool*) malloc(SIZE * sizeof(bool));

	for (int i = 0; i < SIZE; ++i)
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
	if (ex == SIZE) ex--;
	if (ey == SIZE) ey--;

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

	pattern = (bool**) malloc(SIZE * sizeof(bool*));
	inlet.open(path, std::fstream::in);

	for (int i = 0; i < SIZE; ++i)
	{
		std::getline(inlet, line);
		pattern[i] = process_line(line.c_str());
	}

	id = identifier;
	inlet.close();
}

void Letter::write()
{
	std::cout << "---" << std::endl;

	for (int j = 0; j < SIZE; ++j)
	{
		for (int i = 0; i < SIZE; ++i)
			std::cout << ((pattern[j][i] == true)? '#' : ' ');
		std::cout << std::endl;
	}
}

float Letter::compare(Letter to_compare)
{
	float score = 0;
	int no_points = 0;

	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (pattern[x][y] == true)
				score += compare_slots(x, y, to_compare),
				++no_points;

	return score/no_points;
}

int Letter::get_side()
{
	return side;
}

bool Letter::get_pattern(int x, int y)
{
	return pattern[x][y];
}

char Letter::get_id()
{
	return id;
}

void Letter::set_id(char new_id)
{
	this->id = new_id;
}

void Letter::set_pattern(bool **new_pattern)
{
	this->pattern = new_pattern;
}

#undef SIZE
#endif
