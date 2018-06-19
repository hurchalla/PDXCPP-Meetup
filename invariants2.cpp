#include <assert.h>


// in practice we'd move this class into its own header file
template <typename T>
class InvariantsGuard
{
public:
     explicit InvariantsGuard(T& obj) : obj_(obj)
     {
       obj_.CheckInvariants();
     }
     ~InvariantsGuard()
     {
       obj_.CheckInvariants();
     }
     InvariantsGuard(const InvariantsGuard&) = delete;
     InvariantsGuard& operator=(const InvariantsGuard&) = delete;
private:
     T& obj_;
};


class Widget
{
public:
    void foo()
    {
      InvariantsGuard<Widget>(*this);
      // ...
      // function body
      // ...
    }

    void bar()
    {
      InvariantsGuard<Widget>(*this);
      // ...
      // function body
      // ...
    }

private:
    friend InvariantsGuard<Widget>;  // !!
    void CheckInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};

