#include "lib.hpp"



extern "C" {

  byte *get_register (const char	*name,
		     int		depth)
  {
    for (int i = 0; i < 32; ++i)
      {
	if (strcmp(name, tab[i]) == 0)
	  {
	    if (i < 8)
	      return (byte *) &_mpc.globals[i];
	    else if (i < 16)
	      return (byte *) &_mpc.local[depth].inputs[i - 8];
	    else if (i < 24)
	      return (byte *) &_mpc.local[depth].local[i - 16];
	    else
	      return (byte *) &_mpc.local[depth + 1].inputs[i - 24];
	  }
      }
    return NULL;  

  }

}
