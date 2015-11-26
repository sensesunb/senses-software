#!c:\python27\python.exe
def extract(line):
	cells = line.split('\t')
	letter = cells[0]
	code = 0



	return letter, code

def mine(fp):
	table = dict()

	for i, line in enumerate(inlet):
		if i == 0:
			continue
		elif i == 84: # because thats 42*2
			break
		else:
			letter, code = extract(line)
			table[letter] = code

	return table

def get_header():
	return """#pragma once
#include <stdlib.h>
#ifndef byte
#define byte unsigned char
#endif

/* DECIDE IF LETTER HAS A PRECEDING BRAILLE */

byte letter2code(char letter)
{
  byte *code = (byte*) malloc(2*sizeof(byte));

  switch (letter)
  {
"""

def format(linenumber, content):
	output = '    '

	if content != 'null':
		flag = False
		for it in map(lambda x: x.rstrip(), content.split(' ')):
			if len(it) <= 1:
				if it != '\'':
					output += 'case \'%s\': ' % (it)
				else:
					output += 'case \'\\\'\': '
				flag = True
		if flag:
			output += 'return %d; break;\n' % (linenumber)

	return output

def close_header():
	return """
    default:
	  free(code);
	  code = NULL;
  }

  return code;
}
"""

def main(inlet, outlet):
	outlet.write(get_header())
	for letter, braille in mine(inlet):
		outlet.write(format(braille, letter))
	outlet.write(close_header())

if __name__ == '__main__':
	inlet = open('braille.csv', 'r')
	outlet = open('bit2letter.h', 'w')
	main(inlet, outlet)
	inlet.close()
	outlet.close()
