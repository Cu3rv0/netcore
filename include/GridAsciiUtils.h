#pragma once
#include "Grid.h"
#include <string>
#include "Node.h"

namespace GridAsciiUtils
{
   std::string GridToText(const Grid&);
   Grid TextToGrid(const std::string&);

   char NodeTypeToChar(NodeType type);
   NodeType CharToNodeType(char);
}
