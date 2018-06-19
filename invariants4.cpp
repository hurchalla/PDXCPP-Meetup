#include <assert.h>


class Widget
{
public:
    void foo()
    {
      using outerClassPtrType = decltype(this);
      class InvariantsGuard {
      public:
          explicit InvariantsGuard(outerClassPtrType ptr) : pOuter(ptr)
          {
              pOuter->CheckInvariants();
          }
          ~InvariantsGuard()
          {
              pOuter->CheckInvariants();
          }
          InvariantsGuard(const InvariantsGuard&) = delete;
          InvariantsGuard& operator=(const InvariantsGuard&) = delete;
      private:
          outerClassPtrType pOuter;
      } guard(this);
      
      // ...
      // foo() function body
      // ...
    }

private:
    void CheckInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};
