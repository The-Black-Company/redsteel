
#include "lib.hpp"
#include <unistd.h>

ubyte *ram;
MicroProcessorMemory _mpc;
bool c;
const char *tab[32] = { "PC", "SR", "SP", "G0", "G1", "G2", "G3", "G4", "I0", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "L0", "L1", "L2", "L3", "L4", "L5", "L6", "L7", "O0", "O1", "O2", "O3", "O4", "O5", "O6", "O7" };

extern "C" {
  void run_device(void)
  {
    _mpc.pc = 0;
    while(1)
      {
	if (c == true)
	  {
	    print_ram();
	    c = false;
	    usleep(1e2);
	  }
      }
  }
}
