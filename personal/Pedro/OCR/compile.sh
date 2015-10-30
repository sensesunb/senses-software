clear
g++ -I/usr/local/include `pkg-config --cflags --libs opencv2 tesseract` tesscv.cpp -o tesscv
