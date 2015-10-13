options = -lm -O3 -ansi -Wall -pipe
addpath = -I"boolean" -I"grey-sense/src" -I"greyscale/src" -I"many"

cropper: grey-sense/src/cropper.hpp
comparator: grey-sense/src/comparator.hpp
sense: grey-sense/src/sensor.cpp grey-sense/src/sensor.hpp cropper comparator
	g++ grey-sense/src/sensor.cpp -o sense $(options) $(addpath)
sensor: sense
many: sensor comparator cropper
	g++ many/many.cpp -o many.exe $(options) $(addpath)
