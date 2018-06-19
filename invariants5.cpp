#include <assert.h>

//
// in practice this macro would be in a header file
//
#define INVARIANTS_GUARD(INVARIANTS_METHOD_NAME) \
      using outerClassPtrType = decltype(this); \
      class InvariantsGuard { \
      public: \
          explicit InvariantsGuard(outerClassPtrType ptr) : pOuter(ptr) \
          { \
              pOuter->INVARIANTS_METHOD_NAME(); \
          } \
          ~InvariantsGuard() \
          { \
              pOuter->INVARIANTS_METHOD_NAME(); \
          } \
          InvariantsGuard(const InvariantsGuard&) = delete; \
          InvariantsGuard& operator=(const InvariantsGuard&) = delete; \
      private: \
          outerClassPtrType pOuter; \
      } guard(this)


class Widget
{
public:
    void foo()
    {
      INVARIANTS_GUARD(CheckInvariants);
      // ...
      // foo() function body
      // ...
    }
    void bar()
    {
      INVARIANTS_GUARD(CheckInvariants);
      // ...
      // bar() function body
      // ...
    }

private:
    void CheckInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};
