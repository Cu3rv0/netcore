#pragma once
#include "Grid.h"
#include <string>

namespace GridAsciiUtils
{
   std::string GridToText(const Grid&);
   Grid TextToGrid(const std::string&);
}
