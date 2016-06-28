#ifndef WRITER_H
#define WRITER_H
#include <stdlib.h>
#include "image.h"
#include "sink.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class PNMwriter : public Sink{
    public:
	void Write(char *);
};

#endif
