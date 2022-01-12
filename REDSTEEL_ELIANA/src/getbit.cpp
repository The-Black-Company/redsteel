#include "lib.hpp"

extern "C" {
  char getbit(char c, int i)
  {
    return ((c >> i) & 1);
  }
}
