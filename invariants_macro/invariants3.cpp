#include <assert.h>


class Widget
{
public:
    void foo()
    {
      class InvariantsGuard {
      public:
          explicit InvariantsGuard(Widget* ptr) : pOuter(ptr)
          {
              pOuter->checkInvariants();
          }
          ~InvariantsGuard()
          {
              pOuter->checkInvariants();
          }
          InvariantsGuard(const InvariantsGuard&) = delete;
          InvariantsGuard& operator=(const InvariantsGuard&) = delete;
      private:
          Widget* pOuter;
      } guard(this);
      
      // ...
      // foo() function body
      // ...
    }

private:
    void checkInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};
