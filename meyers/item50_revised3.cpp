#include <cstddef>
#include <memory>

static const int signature = 0xDEADBEEF;
typedef unsigned char Byte;

void* signedAllocate(std::size_t size)
{
  using namespace std;

  size_t alignedSize = (size % sizeof(int) == 0) ? size :
                          size + sizeof(int) - size % sizeof(int);

  size_t realSize = alignedSize + sizeof(int); // increase size of request so a
                                               // signature will fit at the end
  
  void *pMem = malloc(realSize);              // call malloc to get the actual
  if (!pMem) throw bad_alloc();               // memory

  //write signature into last part of the memory
  Byte* pMemSignature = static_cast<Byte*>(pMem)+realSize-sizeof(signature);
  auto pSignature = ::new (pMemSignature) int;
  *pSignature = signature;

  // return a pointer to the memory
  return pMem;
}
