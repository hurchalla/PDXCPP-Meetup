#include <assert.h>


// in practice we'd move this class into its own header file
template <typename T>
class InvariantGuard
{
public:
     explicit InvariantGuard(T& obj) : obj_(obj)
     {
       obj_.CheckInvariants();
     }
     ~InvariantGuard()
     {
       obj_.CheckInvariants();
     }
     InvariantGuard(const InvariantGuard&) = delete;
     InvariantGuard& operator=(const InvariantGuard&) = delete;
private:
     T& obj_;
};


class Widget
{
public:
    void foo()
    {
      InvariantGuard<Widget>(*this);
      // ...
      // function body
      // ...
    }

    void bar()
    {
      InvariantGuard<Widget>(*this);
      // ...
      // function body
      // ...
    }

private:
    friend InvariantGuard<Widget>;  // !!
    void CheckInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};

