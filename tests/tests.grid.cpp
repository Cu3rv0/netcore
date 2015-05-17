#include "gtest/gtest.h"
#include "Grid.h"
#include "GridAsciiUtils.h"
#include <memory>
#include <string>
#include <stdexcept>

using namespace std;
using namespace GridAsciiUtils;

class GridTests: public ::testing::Test
{
public:
   unique_ptr<Grid> m_grid;

   GridTests():
      m_grid(make_unique<Grid>(4,4))
   {
   }
   ~GridTests() {}
};


TEST_F(GridTests, Empty_grid_is_converted_to_ascii_grid)
{
   string expected = "----\n"
                     "----\n"
                     "----\n"
                     "----\n";

   string actual = GridToText(*m_grid);

   ASSERT_EQ(expected,actual);
}

TEST_F(GridTests, String_is_converted_to_empty_grid)
{
   string stringToConvert = "----\n"
                            "----\n"
                            "----\n"
                            "----\n"; 

   string actual = GridToText(TextToGrid(stringToConvert));

   ASSERT_EQ(stringToConvert,actual);
}

TEST_F(GridTests, Conversion_throws_when_turning_malformed_string_into_grid)
{
   string malformedString = "---\n"
                            "--\n";

   ASSERT_THROW(TextToGrid(malformedString),runtime_error);
}

TEST_F(GridTests, Closed_node_character_conversion)
{
   string stringGridWithClosedNodes = " -- \n"
                                      " -- \n"
                                      " -- \n"
                                      " -- \n"; 

   Grid gridWithClosedNodes = TextToGrid(stringGridWithClosedNodes);
   
   ASSERT_EQ(NodeType::Closed,gridWithClosedNodes.at(0,0));
   
   string convertedStringGrid = GridToText(gridWithClosedNodes);

   ASSERT_EQ(stringGridWithClosedNodes, convertedStringGrid);
}

TEST_F(GridTests, Port_Node_Character_Conversion)
{
   string stringGridWithPorts = "---P\n"
                                "----\n"
                                "----\n"
                                "P---\n"; 

   Grid gridWithPorts = TextToGrid(stringGridWithPorts);
   
   ASSERT_EQ(NodeType::Port, gridWithPorts.at(0,3));
   
   string convertedStringGrid = GridToText(gridWithPorts);

   ASSERT_EQ(stringGridWithPorts, convertedStringGrid);

}

TEST_F(GridTests, Cache_Node_Character_Conversion)
{
   string stringGridWithCache = "C---\n"
                                "----\n"
                                "----\n"
                                "----\n"; 

   Grid gridWithCache = TextToGrid(stringGridWithCache);
   
   ASSERT_EQ(NodeType::Cache, gridWithCache.at(0,0));
   
   string convertedStringGrid = GridToText(gridWithCache);

   ASSERT_EQ(stringGridWithCache, convertedStringGrid);
}

TEST_F(GridTests, Socket_Node_Character_Conversion)
{
   string stringGridWithSocket = "X---\n"
                                 "----\n"
                                 "----\n"
                                 "----\n"; 

   Grid gridWithSocket = TextToGrid(stringGridWithSocket);
   
   ASSERT_EQ(NodeType::Socket, gridWithSocket.at(0,0));
   
   string convertedStringGrid = GridToText(gridWithSocket);

   ASSERT_EQ(stringGridWithSocket, convertedStringGrid);
}
