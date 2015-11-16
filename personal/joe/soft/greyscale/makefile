options = -lm -O3 -Wall -ansi -pipe
srcf = -I"src"

bm: src/bitmap.c
	gcc src/bitmap.c -o bm.exe $(options) $(srcf)
grey: src/greyscale.h src/greyscale.c
	gcc src/greyscale.c -o grey.exe $(options) $(srcf)
test: src/test.c
	gcc src/test.c -o test.exe
comp: src/compare.c src/greyscale.h src/bitmap.h
	gcc src/compare.c -o comp.exe $(options) $(srcf)
