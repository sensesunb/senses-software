REM mingw32-make sense
REM more input.txt | gdb sense.exe
REM del *exe

mingw32-make many
many tests/arial-8.bmp
many tests/input-text-pi.bmp
many tests/arial-text-phi.bmp

REM cd greyscale
REM mingw32-make bm
REM move bm.exe ..
REM cd ..
REM bm.exe tests\arial-8.bmp
REM bm.exe tests\arial-text-phi.bmp > phi.txt
