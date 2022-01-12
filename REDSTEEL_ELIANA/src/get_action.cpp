#include "lib.hpp"


extern "C" {
  void get_action ()
  {
    int a = 0, b = 0, c = 0;

    for (int i  = 5; i >= 0; --i)
      {
	if (getbit(*ram, i) == 1)
	    BITSET(a, 5 - i);
      }
    
    for (int i  = 31; i >= 16; --i)
      {
	if (getbit(*ram, i) == 1)
	    BITSET(b, i - 16);
      }

    for (int i  = 32 + 15; i >= 32; --i)
      {
	if (getbit(*ram, i) == 1)
	    BITSET(c, i - 32);
      }
    
    printf("a = ");
    for (int i  = 0; i < 8; ++i)
      printf("%d", getbit(a, i));
    printf("[b = %d][c = %d]\n", b, c);

    
    
    
    printf("intruction == %d\n", a);
  }
}
