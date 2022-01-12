#include "lib.hpp"


extern "C" {
  void set_memory(byte *mem)
  {
    ram = (ubyte *) mem;
  }
}
