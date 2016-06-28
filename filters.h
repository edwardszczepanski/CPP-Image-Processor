#ifndef FILTERS_H
#define FILTERS_H
#include <string.h>
#include <stdlib.h>
#include "image.h"
#include "source.h"
#include "sink.h"
#include <stdio.h>

class Filter : public Source, public Sink{
public:
  Filter();
  virtual void Execute();
protected:
  virtual void Update();
};

class Shrinker : public Filter {
public:
  Shrinker();
  void Execute();
};

class LRConcat : public Filter {
public:
  void Execute();
};

class TBConcat : public Filter {
public:
  void Execute();
};

class Blender : public Filter {
private:
  float factor;
public:
  void Execute();
  void SetFactor(float);
};

#endif
