#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>

class Source {
protected:
  Image image;
  virtual void Execute () = 0;
public:
  virtual void Update();
  Image * GetOutput ();
  Source(void);
};

#endif
