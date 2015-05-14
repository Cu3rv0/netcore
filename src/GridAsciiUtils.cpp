#include "GridAsciiUtils.h"

using namespace std;

string GridAsciiUtils::GridToText(const Grid& grid)
{
   string gridString("");
   for (unsigned int x = 0; x != grid.GetWidth(); x++) {
      for (unsigned int y = 0; y != grid.GetHeigth(); y++) {
         gridString += NodeTypeToChar(grid.at(x,y).GetType());
      }
      gridString += '\n';
   }

   return gridString;
}

char GridAsciiUtils::NodeTypeToChar(NodeType type)
{
   switch (type)
   {
   case NodeType::Open:
      return '-';
   default:
      return 'x';
   }
}
