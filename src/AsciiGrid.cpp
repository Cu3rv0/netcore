#include "AsciiGrid.h"

using namespace std;

AsciiGrid::AsciiGrid(unsigned int x, unsigned int y) {

   m_nodes.resize(x);
   for(auto column : m_nodes) {
      column.resize(y);
   }
}

const AsciiGrid::NodeInterface& at(unsigned int x, unsigned int y) {
   return nodes.at(x,y).get();
}
