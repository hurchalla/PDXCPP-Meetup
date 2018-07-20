#include <assert.h>


// in practice we'd move this class into its own header file
template <typename T>
class InvariantsGuard
{
public:
     explicit InvariantsGuard(T& obj) : obj_(obj)
     {
       obj_.checkInvariants();
     }
     ~InvariantsGuard()
     {
       obj_.checkInvariants();
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
      InvariantsGuard<Widget> invariantsGuard(*this);
      // ...
      // function body
      // ...
    }

    void bar()
    {
      InvariantsGuard<Widget> invariantsGuard(*this);
      // ...
      // function body
      // ...
    }

private:
    friend class InvariantsGuard<Widget>;  // !!
    void checkInvariants()
    {
      assert(1 + 1 == 2);
      assert(2 * 2 == 4);
    }
};

