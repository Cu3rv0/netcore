#include "GridAsciiUtils.h"
#include <stdexcept>

using namespace std;

string GridAsciiUtils::GridToText(const Grid& grid)
{
   string gridString("");
   for (unsigned int y = 0; y != grid.GetHeigth(); y++) {
      for (unsigned int x = 0; x != grid.GetWidth(); x++) {
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
   case NodeType::Closed:
      return ' ';
   case NodeType::Port:
      return 'P';
   case NodeType::Cache:
      return 'C';
   case NodeType::Socket:
      return 'X';
   default:
      return '?';
   }
}

NodeType GridAsciiUtils::CharToNodeType(char typeInChar)
{
   switch (typeInChar)
   {
      case '-':
         return NodeType::Open;
      case ' ':
         return NodeType::Closed;
      case 'P':
         return NodeType::Port;
      case 'C':
         return NodeType::Cache;
      case 'X':
         return NodeType::Socket;
      default:
         throw(std::runtime_error("Malformed String"));
   }
}

Grid GridAsciiUtils::TextToGrid(const string& text)
{
   unsigned int gridWidth = text.find('\n');
   unsigned int gridHeight = text.size() / (gridWidth + 1);
   
   if (!gridWidth || (text.size() % (gridWidth + 1)))
      throw(std::runtime_error("Malformed String"));

   Grid returnGrid(gridWidth,gridHeight);
   for (unsigned int y = 0; y != gridHeight; y++)
   {
      for (unsigned int x = 0; x != gridWidth; x++)
      {
         char nodeChar = text[x + y*(gridWidth + 1)];
         returnGrid.at(x,y).SetType(CharToNodeType(nodeChar));
      }
   }
   return returnGrid;
}
