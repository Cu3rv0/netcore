#include "gtest/gtest.h"
#include "Grid.h"
#include "GridAsciiUtils.h"
#include <memory>
#include <string>

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
