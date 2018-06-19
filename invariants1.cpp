#include <assert.h>


class Widget
{
public:
    void foo()
    {
      CheckInvariants();
      // ...
      // function body
      // ...
      CheckInvariants();
    }

    void bar()
    {
      CheckInvariants();
      // ...
      // function body
      // ...
      CheckInvariants();
    }

private:
    void CheckInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};
