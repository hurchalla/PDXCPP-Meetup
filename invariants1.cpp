#include <assert.h>

class Widget
{
public:
    void foo()
    {
      checkInvariants();
      try {
         // ...
         // foo() function body
         // ...
      } catch (...) {
         checkInvariants();
         throw;
      }
      checkInvariants();
    }

    void bar()
    {
      checkInvariants();
      try {
         // ...
         // bar() function body
         // ...
      } catch (...) {
         checkInvariants();
         throw;
      }
      checkInvariants();
    }

private:
    void checkInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};
