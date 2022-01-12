#include "lib.hpp"

static ubyte set_sr()
{
  ubyte cvbtab[11] = {ZR, CR, OF, NG, EQ, DF, LT, LE, GT, GE, CD};
  ubyte result = 0;
  for (int i = 0; i < 11; i++)
    {
      //      printf("%d * %d\n", cvbtab[i], _mpc._CVB[i]);
      result += cvbtab[i] * _mpc._CVB[i];
    }
  return result;
}


extern "C" {
  void print_ram (void)
  {
    if (_mpc.pc > 0xFFFF) // 131072
      {
	printf("%sTHIS IS REBBOT%s\n", KCYN, KNRM);
	_mpc.pc = 0;
      }

    if (_mpc.sr < 80)
      _mpc.sr++;
    else
      _mpc.sr = 0;
    
    t_inst a, b, c;
    a.ram = ram[0 + _mpc.pc];
    b.ram = ram[1 + _mpc.pc];
    c.ram = ram[2 + _mpc.pc];

    _mpc.pc = _mpc.pc + 3; 
    set_action (a, b.ram, c.ram);

    _mpc.sr = set_sr();

  }
}


    /*
    if (b.ram != 0 && a.ram != 0)
      {
	printf("NUMERO D'INSTRUCTION : %d\n", a.inst.ni);
	printf("Mode d'accès pour premier registre : %d\n", a.inst.fam);
	printf("Modificateur de premier registre : %d\n", a.inst.fm);
	printf("Mode d'accès pour second registre : %d\n", a.inst.sam);
	printf("Modificateur de second registre : %d\n", a.inst.sm);
	printf("\n{val-1=%d;val-2=%d}\n", b.ram, c.ram);
      }
    */
