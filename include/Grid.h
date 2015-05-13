#pragma once

#include "Node.h"
#include "GridInterface.h"
#include <vector>
#include <memory>

class Grid: public GridInterface {

public:
  virtual const NodeInterface& at(unsigned int, unsigned int);

private:
   std::vector<std::vector<std::unique_ptr<Node> > > m_nodes;
{
