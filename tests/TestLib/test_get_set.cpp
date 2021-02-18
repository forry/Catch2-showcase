#include <catch2/catch.hpp>

#include <LibClass.h>

SCENARIO("Basic set/get testing","[unit]")
{
   GIVEN("The LibClass object")
   {
      LibClass lc;

      WHEN("We set the value to 3")
      {
         lc.set(3);

         THEN("We should get 3")
         {
            REQUIRE(lc.get() == 3);
         }
      }
      WHEN("When we don't set anything")
      {
         THEN("We should get 0")
         {
            REQUIRE(lc.get() == 0);
         }
      }
   }
}