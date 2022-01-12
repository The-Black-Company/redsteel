#include "lib.hpp"
extern "C" {
  static void set_a (ubyte **_A, t_inst inst, ubyte *a);
  static void set_b (ubyte **_B, t_inst inst, ubyte *b);

  void set_action (t_inst inst, ubyte a, ubyte b)
  {
    ubyte *_A = NULL, *_B = NULL;
  
    set_a (&_A, inst, &a);
    set_b (&_B, inst, &b);

    if (inst.inst.ni == 0)
      SET(_A, _B);
    else if (inst.inst.ni == 1)
      ADD(_A, _B);
    else if (inst.inst.ni == 2)
      SUB(_A, _B);
    else if (inst.inst.ni == 3)
      AND(_A, _B);
    else if (inst.inst.ni == 4)
      IOR(_A, _B);
    else if (inst.inst.ni == 5)
      XOR(_A, _B);
    else if (inst.inst.ni == 6)
	COMPARE(_A, _B);
    else if (inst.inst.ni == 7)
      _mpc.pc = IF (1, _A, _B);
    else if (inst.inst.ni == 8)
      _mpc.pc = IF (0, _A, _B);
    else if (inst.inst.ni == 9)
      _mpc.pc = IF (2, _A, _B);
    else if (inst.inst.ni == 10)
      _mpc.pc = IF (3, _A, _B);
    else if (inst.inst.ni == 11)
      _mpc.pc = IF (6, _A, _B);
    else if (inst.inst.ni == 12)
      _mpc.pc = IF (8, _A, _B);
    else if (inst.inst.ni == 13)
      _mpc.pc = IF (7, _A, _B);
    else if (inst.inst.ni == 14)
      _mpc.pc = IF (9, _A, _B);
    else if (inst.inst.ni == 15)
      _mpc.pc = IF (4, _A, _B);
    else if (inst.inst.ni == 16)
      _mpc.pc = IF (5, _A, _B);
    else if (inst.inst.ni == 17)
      {
	_mpc.local[_mpc.g[4]].inputs[6] = _mpc.pc; 
	_mpc.pc = *_A;
	if (_mpc.g[4] < 127)
	  _mpc.g[4] += 1;
      }
    else if (inst.inst.ni == 18)
      {
	_mpc.pc = _mpc.local[_mpc.g[4]].inputs[6]; 
	if (_mpc.g[4] > 0)
	  _mpc.g[4] -= 1;
      }
    else if (inst.inst.ni == 19)
      SHL(_A, _B);
    else if (inst.inst.ni == 20)
      SHR(_A, _B);
    else if (inst.inst.ni == 21)
      MUL(_A, _B);
    else if (inst.inst.ni == 22)
      DIV(_A, _B);
  

    
    if (inst.inst.fam == 2 || inst.inst.fam == 3)
      {
	ubyte *ras = &(_mpc.local[((a - 8) / 16) % 128].inputs[(a - 8) % 16]);
	if (inst.inst.fm == 1)
	  ++(*ras);
	else if (inst.inst.fm == 2)
	  --(*ras);
	else if (inst.inst.fm == 5)
	  --(*ras);
	else if (inst.inst.fm == 6)
	  ++(*ras);
      }

    if (inst.inst.sam == 2 || inst.inst.sam == 3)
      {
	ubyte *rbs = &(_mpc.local[((b - 8) / 16) % 128].inputs[(b - 8) % 16]);
	if (inst.inst.sm == 1)
	  (*rbs)++;
	else if (inst.inst.sm == 2)
	  (*rbs)--;
	else if (inst.inst.sm == 5)
	  (*rbs)--;
	else if (inst.inst.sm == 6)
	  (*rbs)++;
      }

    
  }





  static void set_a (ubyte **_A, t_inst inst, ubyte *a)
  {
    if (inst.inst.fam == 0)
      *_A = a;
    else if (inst.inst.fam == 1)
      *_A = &(ram[*a]);
    else if (inst.inst.fam == 2)
      {
	if (*a < 8)
	  *_A = &(_mpc.globals[*a]);
	else
	    *_A = &(_mpc.local[((*a - 8) / 16) % 128].inputs[(*a - 8) % 16]);
      }
    else if (inst.inst.fam == 3)
      {
	if (*a < 8)
	  *_A = &ram[(_mpc.globals[*a])];
	else
	  *_A = &ram[(_mpc.local[((*a - 8) / 16) % 128].inputs[(*a - 8) % 16])];
      }
    
    if (inst.inst.fam == 2 || inst.inst.fam == 3)
      {
	ubyte *ras = &(_mpc.local[((*a - 8) / 16) % 128].inputs[(*a - 8) % 16]);
	if (inst.inst.fm == 3)
	  ++(*ras);
	else if (inst.inst.fm == 4)
	  --(*ras);
	else if (inst.inst.fm == 5)
	  --(*ras);
	else if (inst.inst.fm == 6)
	  ++(*ras);
      }
  }

  static void set_b (ubyte **_B, t_inst inst, ubyte *b)
  {
    if (inst.inst.sam == 0)
      *_B = NULL;
    else if (inst.inst.sam == 1)
      *_B = &(ram[*b]);
    else if (inst.inst.sam == 2)
      {
	if (*b < 8)
	  *_B = &(_mpc.globals[*b]);
	else
	  *_B = &(_mpc.local[((*b - 8) / 16) % 128].inputs[(*b - 8) % 16]);
      }
    else if (inst.inst.sam == 3)
      {
	if (*b < 8)
	  *_B = &ram[(_mpc.globals[*b])];
	else
	  *_B = &ram[(_mpc.local[((*b - 8) / 16) % 128].inputs[(*b - 8) % 16])];
      }

    if (inst.inst.sam == 2 || inst.inst.sam == 3)
      {
	ubyte *ras = &(_mpc.local[((*b - 8) / 16) % 128].inputs[(*b - 8) % 16]);
	if (inst.inst.sm == 3)
	  ++(*ras);
	else if (inst.inst.sm == 4)
	  --(*ras);
	else if (inst.inst.sm == 5)
	  --(*ras);
	else if (inst.inst.sm == 6)
	  ++(*ras);
      }
  }  
}
