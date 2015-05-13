#pragma once
#include "NodeInterface.h"

class GridInterface {
public:
   virtual ~GridInterface() {}

   virtual const Node& at(unsigned int x, unsigned int y) = 0;
};
