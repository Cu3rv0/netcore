#pragma once
#include "GridInterface.h"
#include <vector>
#include <memory>

class AsciiGrid: public GridInterface
{
public:
   AsciiGrid(unsigned int, unsigned int);

   const NodeInterface& at(unsigned int, unsigned int);
private:
   std::vector<std::vector<std::unique_ptr<NodeInterface> > > m_nodes;

};



