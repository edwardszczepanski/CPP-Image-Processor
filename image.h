#ifndef IMAGE_H
#define IMAGE_H
#include <stdlib.h>

class Pixel {
    public:
	unsigned char r, g, b;
};

class Source;

class Image {
	private:
	int x, y;
	Pixel *data;
    public:
	Source * sourcePointer;
	Image (void);
	Image (int x, int y, Pixel* pixelInfo);
	Image (Image *image);
	~Image() { free(data); };
	int getX();
	int getY();
	Pixel * getData();
	void setX(int);
	void setY(int);
	//void setData(int, Pixel *);
  	void setData(Pixel *);
  	void allocateData(int size);
	void setSize(int width, int height);
	void SetSource(Source *);
	virtual void Update();
};

#endif
