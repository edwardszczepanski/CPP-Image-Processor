#include "sink.h"

Sink::Sink(void) { }

void Sink::SetInput(Image *input1){
	image1 = input1;
}

void Sink::SetInput2(Image *input2){
	image2 = input2;
}
