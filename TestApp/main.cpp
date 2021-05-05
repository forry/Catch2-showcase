#include <iostream>
#include <LibraryLoader.h>
#include <catch2/catch_session.hpp>

using namespace std;

using voidPFN = void(*)();

int main()
{
   LibraryLoader testdll("tests");
   voidPFN run=testdll.resolve<voidPFN>("run");
   if(!run)
   {
      cout << "not run" << endl;
   }
   run();
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
   cout << "This doesn't find any tests:\n";
   Catch::Session().run();
   cout << "This Project is a Catch2 showcase. This executable does nothing.\n";
   return 0;
}