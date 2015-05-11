#include "gtest/gtest.h"
#include "grid.h"
#include <memory>

using namespace std;

class GridTests: public ::testing::Test
{
public:
   unique_ptr<Grid> m_grid;

   GridTests():
      m_grid(make_unique<Grid>(3,4))
   {
   }
   ~GridTests() {}
};


TEST_F(GridTests, skeleton_test)
{

}
