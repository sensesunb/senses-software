REM mingw32-make sense
REM more input.txt | gdb sense.exe
REM del *exe

REM mingw32-make many
REM many tests/arial-8.bmp
REM many tests/input-text-pi.bmp
REM many tests/arial-text-phi.bmp

REM cd greyscale
REM mingw32-make bm
REM move bm.exe ..
REM cd ..
REM bm.exe tests\arial-8.bmp
REM bm.exe tests\arial-text-phi.bmp > phi.txt

mingw32-make identifier
identify tests/arial-8.bmp
identify tests/input-text-pi.bmp
identify tests/arial-text-phi.bmp

del *.exe
