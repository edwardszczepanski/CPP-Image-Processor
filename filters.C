#include "filters.h"

Filter::Filter() { }

Shrinker::Shrinker() { }

void Filter::Update() {
	if (image1 != NULL) {
		image1->Update();
	}
	Execute();
}

void Filter::Execute(){ }

void Shrinker::Execute() {
  int width = (int)image1->getX() / 2;
  int height = (int)image1->getY() / 2;
  image.setSize(width, height);
  //image.setData((Pixel*)malloc(width * height * sizeof(Pixel)));
  Pixel *source = image.getData();
  Pixel *sink1 = image1->getData();

  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      source[j * width + i] = sink1[2 * j * image1->getX() + 2 * i];
    }
  }
}

void LRConcat::Execute() {
  image.setSize(image1->getX() + image2->getX(), image1->getY());
  Pixel *source = image.getData();
  Pixel *sink1 = image1->getData();
  Pixel *sink2 = image2->getData();

  for (int i = 0; i < image1->getX() + image2->getX(); ++i) {
    for (int j = 0; j < image1->getY(); ++ j) {
      if (i < image1->getX()) {
        source[j * image.getX() + i] = sink1[j * image1->getX() + i];
      }
      else {
        source[j * image.getX() + i] = sink2[j * image2->getX() + (i - image1->getX())];
      }
    }
  }
}

void TBConcat::Execute() {
  image.setSize(image1->getX(), image1->getY() + image2->getY());
  Pixel *source = image.getData();
  Pixel *sink1 = image1->getData();
  Pixel *sink2 = image2->getData();

  for (int i = 0; i < image1->getX(); ++i) {
    for (int j = 0; j < image1->getY() + image2->getY(); ++j) {
      if (j < image1->getY()) {
        source[j * image.getX() + i] = sink1[(j * image1->getX()) + i];
      }
      else {
        source[j * image.getX() + i] = sink2[(j - image1->getY()) * image2->getX() + i];
      }
    }
  }
}

void Blender::SetFactor(float input) {
  factor = input;
}

void Blender::Execute() {
  image.setSize(image1->getX(), image1->getY());
  Pixel *source = image.getData();
  Pixel *sink1 = image1->getData();
  Pixel *sink2 = image2->getData();
  for (int i = 0; i < image1->getX(); ++i) {
    for (int j = 0; j < image1->getY(); ++j) {
      source[j * image1->getX() + i].r = sink1[j * image1->getX() + i].r * factor +  sink2[j * image2->getX() + i].r * (1 - factor);
      source[j * image1->getX() + i].g = sink1[j * image1->getX() + i].g * factor +  sink2[j * image2->getX() + i].g * (1 - factor);
      source[j * image1->getX() + i].b = sink1[j * image1->getX() + i].b * factor +  sink2[j * image2->getX() + i].b * (1 - factor);
    }
  }
}
