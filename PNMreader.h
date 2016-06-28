#ifndef READER_H
#define READER_H
#include <string.h>
#include <stdlib.h>
#include "image.h"
#include "source.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class PNMreader : public Source {
public:
  char *fileName;
	PNMreader(char *filename);
	~PNMreader() { delete[] fileName; };
	virtual void Execute(void);
};

#endif
