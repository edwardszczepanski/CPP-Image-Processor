#include "source.h"

Source::Source(void) { 
	image.SetSource(this);
}

void Source::Update() {
	Execute();
}

Image * Source::GetOutput() {
	return &image;
}


