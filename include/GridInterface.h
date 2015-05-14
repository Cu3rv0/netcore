#pragma once
#include "Node.h"

class GridInterface {
public:
   virtual ~GridInterface() {}

   virtual const Node& at(unsigned int x, unsigned int y) = 0;
   virtual unsigned int GetWidth() = 0;
   virtual unsigned int GetHeigth() = 0;
};
