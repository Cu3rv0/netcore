#pragma once

#include "Node.h"
#include "GridInterface.h"
#include <vector>
#include <memory>

class Grid: public GridInterface {

public:
   Grid(unsigned int, unsigned int);
   virtual Node& at(unsigned int, unsigned int);
   virtual const Node& at(unsigned int, unsigned int) const;

   virtual unsigned int GetWidth() const;
   virtual unsigned int GetHeigth() const;;

private:
   unsigned int m_width, m_height;
   
   void ConstructNodes();

   std::vector<std::vector<std::unique_ptr<Node> > > m_nodes;
};
