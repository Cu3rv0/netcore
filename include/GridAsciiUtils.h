#pragma once
#include "Grid.h"
#include <string>
#include "Node.h"

namespace GridAsciiUtils
{
   std::string GridToText(const Grid&);

   char NodeTypeToChar(NodeType type);
}
