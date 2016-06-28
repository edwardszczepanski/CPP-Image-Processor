#include "PNMreader.h"

PNMreader::PNMreader(char *filename) {
	fileName = new char[strlen(filename) + 1];
	strcpy(fileName, filename);
}

void PNMreader::Execute() {
	FILE *input = fopen(fileName,"r");
	int width, height;
	fscanf(input,"P6\n%d %d\n255\n", &width, &height);
	//image.setSize(width, height);
	image.setX(width);
	image.setY(height);
	Pixel *temp = (Pixel *) malloc(width * height * sizeof(Pixel));
	fread(temp, sizeof(Pixel), width*height, input);
	image.setData(temp);
	fclose(input);
	free(temp);
}
