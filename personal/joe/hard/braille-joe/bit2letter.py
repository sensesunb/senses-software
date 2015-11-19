def get_header():
	return """#pragma once
#ifndef byte
#define byte unsigned char
#endif

byte letter2code(char letter)
{
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
    default: return '?';
  }
}"""

if __name__ == '__main__':
	b2l = 'bit2letter'
	inlet = open(b2l + '.txt', 'r')
	outlet = open(b2l + '.h', 'w')

	i = 0
	outlet.write(get_header())
	for i, line in enumerate(inlet):
		it = format(i, line)
		if len(it.rstrip()) > 0:
			outlet.write(it)
		i += 1
	outlet.write(close_header())

	inlet.close()
	outlet.close()
