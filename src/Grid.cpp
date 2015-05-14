#include "Grid.h"

using namespace std;

Grid::Grid(unsigned int x, unsigned int y):
   m_width{x},
   m_height{y},
   m_nodes(x)
{
   for (auto& column : m_nodes)
     column.resize(y);

   ConstructNodes();
}

void Grid::ConstructNodes()
{
   for (auto& column : m_nodes)
      for (auto& node : column)
         node = make_unique<Node>();
}

const Node& Grid::at(unsigned int x, unsigned int y) const
{
   return *m_nodes.at(x).at(y);
}

unsigned int Grid::GetWidth() const
{
   return m_width;
}

unsigned int Grid::GetHeigth() const
{
   return m_height;
}
   
