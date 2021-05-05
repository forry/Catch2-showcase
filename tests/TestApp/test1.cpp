#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test1")
{
   CHECK(1==1);
   int a = 1;

   SECTION("podtest1")
   {
      //CHECK('a'=='b');
      CHECK(a==1);
      a++;
   }
   SECTION("podtest2")
   {
      CHECK('c' == 'b');
      CHECK(a == 1);
   }
}