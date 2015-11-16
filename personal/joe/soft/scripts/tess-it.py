import os

"""
# How to loop over files

``` python
import os
for fn in os.listdir('.'):
     if os.path.isfile(fn):
        print (fn)
```
"""

extensions = set([
	'jpg',
	'jpeg',
	'png',
	'gif'])
dot = '.'

def apply(inlet, outlet):
	os.system('tesseract %s %s' % (inlet, outlet))

def deal(fn):
	global extensions
	global dot
	bits = fn.split(dot)
	out = bits[0]

	if bits[-1].lower in extensions:
		if len(bits) > 2:
			for i in xrange(1, len(bits)-1, 1):
				out += dot + bits[i]

	apply(fn, out)

def main():
	global dot

	for fn in os.listdir(dot):
		if os.path.isfile(fn):
			deal(fn)

if __name__ == '__main__':
	main()
