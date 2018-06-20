#include <assert.h>

class Widget
{
public:
    void foo()
    {
      CheckInvariants();
      try {
         // ...
         // foo() function body
         // ...
      } catch (...) {
         CheckInvariants();
         throw;
      }
      CheckInvariants();
    }

    void bar()
    {
      CheckInvariants();
      try {
         // ...
         // bar() function body
         // ...
      } catch (...) {
         CheckInvariants();
         throw;
      }
      CheckInvariants();
    }

private:
    void CheckInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};
