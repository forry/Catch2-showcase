#include <catch2/catch_test_macros.hpp>

#include <SomeClass.h>

SCENARIO("Testing SomeClass","[unit]")
{
   GIVEN("Some class")
   {
      SomeClass sc;

      WHEN("We call canTest(2)")
      {
         THEN("The value returned should be 4")
         {
            REQUIRE(sc.canTest(2) == 5);
         }
      }
   }
}