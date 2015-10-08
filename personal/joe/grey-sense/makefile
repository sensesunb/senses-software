options = -lm -O3 -ansi -pipe -Wall
addpath = -I"../boolean" -I"../greyscale/src" -I"src"

comparator: src/comparator.hpp src/comparator.cpp
	g++ src/comparator.cpp -o comp $(options) $(addpath)
sensor: src/sensor.cpp src/sensor.hpp src/cropper.hpp
	g++ src/sensor.cpp -o sense $(options) $(addpath)
