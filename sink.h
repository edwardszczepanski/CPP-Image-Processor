#ifndef SINK_H
#define SINK_H
#include "image.h"

class Sink {
    protected:
	Image *image1;
	Image *image2;
    public:
	void SetInput(Image *);
	void SetInput2(Image *);
  Sink (void);
};

#endif
