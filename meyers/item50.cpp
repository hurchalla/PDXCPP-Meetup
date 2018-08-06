#include <cstddef>
#include <memory>

static const int signature = 0xDEADBEEF;
typedef unsigned char Byte;

//this code has several flaws -- see below
void* operator new(std::size_t size) throw(std::bad_alloc)
{
  using namespace std;

  size_t realSize = size + 2 * sizeof(int);   // increase size of request so 2
                                              // signatures will also fit inside
  
  void *pMem = malloc(realSize);              // call malloc to get the actual
  if (!pMem) throw bad_alloc();               // memory
  
  //write signature into first and last parts of the memory
  *(static_cast<int*>(pMem)) = signature;
  *(reinterpret_cast<int*>(static_cast<Byte*>(pMem)+realSize-sizeof(int))) = 
    signature;
  
  // return a pointer to the memory just past the first signature
  return static_cast<Byte*>(pMem) + sizeof(int);
}
