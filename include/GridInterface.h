#pragma once
#include "Node.h"

class GridInterface {
public:
   virtual ~GridInterface() {}

   virtual Node& at(unsigned int x, unsigned int y) = 0;
   virtual const Node& at(unsigned int x, unsigned int y) const = 0;
   virtual unsigned int GetWidth() const = 0;
   virtual unsigned int GetHeigth() const = 0;
};
