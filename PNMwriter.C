#include "PNMwriter.h"

void PNMwriter::Write(char *filename) {
	FILE *output;
	output = fopen(filename, "wb");
	fprintf (output, "P6\n");
	fprintf (output, "%d %d\n", image1->getX(), image1->getY());
	fprintf (output, "255\n");
	fwrite(image1->getData(), sizeof(Pixel), image1->getX() * image1->getY(), output);
	fclose(output);
}

