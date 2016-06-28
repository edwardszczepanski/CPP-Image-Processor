#include <image.h>
#include <stdlib.h>
#include <source.h>

Image::Image(void) {
	x = 0;
	y = 0;
	data = NULL;
}

void Image::SetSource(Source * inputSource) {
	sourcePointer = inputSource;
}

void Image::Update() {
		sourcePointer->Update();
}

Image::Image(int _x, int _y, Pixel * _data) {
	x = _x;
	y = _y;
	//data = (Pixel *) malloc(_x * _y * sizeof(Pixel));
	data = _data;
}

Image::Image(Image *_Image) {
	x = _Image->getX();
	y = _Image->getY();
	//data = (Pixel *) malloc(x * y * sizeof(Pixel));
}

int Image::getX() {
	return x;
}

int Image::getY() {
	return y;
}

Pixel * Image::getData() {
	return data;
}

void Image::setX(int xInput) {
	x = xInput;
}

void Image::setY(int yInput) {
	y = yInput;
}

void Image::setData(Pixel * newData) {
	data = (Pixel*) malloc(x * y *sizeof(Pixel));
	for (int i = 0; i < x * y; ++i) {
		data[i] = newData[i];
	}
}


void Image::setSize(int width, int height) {
	if (data != NULL) {
		free(data);
	}
	x = width;
	y = height;
	data = (Pixel*) malloc(x * y *sizeof(Pixel));
}
