#include "lib.hpp"
extern "C" {
  void SET (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	*B = *A;
	_mpc._CVB[0] = 0;
	if (*B == 0)
	  _mpc._CVB[0] = 1;
	if ((byte) *A < 0)
	  _mpc._CVB[3] = 1;
	else
	  _mpc._CVB[3] = 0;
      }
    else
      _mpc._CVB[0] = 1;
  }


  void ADD (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	ubyte tmp = *B;
	*B += *A;
	_mpc._CVB[0] = 0;
	if (*B == 0)
	  _mpc._CVB[0] = 1;
	if ((byte) tmp + (byte) *A < 0)
	  _mpc._CVB[3] = 1;
	else
	  _mpc._CVB[3] = 0;
	if (tmp + *A > 0xFFFFFFFFFFFFFFFF)
	  _mpc._CVB[3] = 1;
	else
	  _mpc._CVB[3] = 0;
	if (tmp + *A > 0xFFFFFFFFFFFFFFFF)
	  _mpc._CVB[2] = 1;
	else
	  _mpc._CVB[2] = 0;
      }
    else
      _mpc._CVB[0] = 1;
  }
  
  void SUB (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	ubyte tmp = *B;
	*B -= *A;
	_mpc._CVB[0] = 0;
	if (*B == 0)
	  _mpc._CVB[0] = 1;
	if ((byte) tmp - (byte) *A < 0)
	  _mpc._CVB[3] = 1;
	else
	  _mpc._CVB[3] = 0;
	if (tmp - *A > (int) 0xFFFFFFFFFFFFFFFF)
	  _mpc._CVB[3] = 1;
	else
	  _mpc._CVB[3] = 0;
	if (tmp - *A > (int) 0xFFFFFFFFFFFFFFFF)
	  _mpc._CVB[2] = 1;
	else
	  _mpc._CVB[2] = 0;
      }
    else
      _mpc._CVB[0] = 1;
  }


  void AND (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	*B &= *A;
	_mpc._CVB[0] = 0;
	if (*B == 0)
	  _mpc._CVB[0] = 1;
      }
    else
      _mpc._CVB[0] = 1;
}



  void IOR (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	*B |= *A;
	_mpc._CVB[0] = 0;
	if (*B == 0)
	  _mpc._CVB[0] = 1;
      }
    else
      _mpc._CVB[0] = 1;
  }

  void XOR (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	*B ^= *A;
	_mpc._CVB[0] = 0;
	if (*B == 0)
	  _mpc._CVB[0] = 1;
      }
    else
      _mpc._CVB[0] = 1;
  }


  ubyte IF (ubyte cmp, ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	return (_mpc._CVB[cmp] == 1) ? *A : *B;
      }
    else
      {
	return (_mpc._CVB[cmp] == 1) ? *A : _mpc.pc;
      }
  }

  void SHL (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	*B >>= *A;
	_mpc._CVB[0] = 0;
	if (*B == 0)
	  _mpc._CVB[0] = 1;
      }
    else
      _mpc._CVB[0] = 1;
  }


  void SHR (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	ubyte tmp = *B;
	*B <<= *A;
	_mpc._CVB[0] = 0;
	if (*B == 0)
	  _mpc._CVB[0] = 1;
	if (tmp - *A > (int) 0xFFFFFFFFFFFFFFFF)
	  _mpc._CVB[3] = 1;
	else
	  _mpc._CVB[3] = 0;
      }
    else
      _mpc._CVB[0] = 1;;
  }


  void MUL (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      *B *= *A;
  }


  void DIV (ubyte *A, ubyte *B)
  {
    if (B != NULL && *A != 0)
      *B /= *A;
  }



  void COMPARE (ubyte *A, ubyte *B)
  {
    if (B != NULL)
      {
	_mpc.sr = (*A < *B) ? 6 : _mpc.sr;
	_mpc.sr = (*A > *B) ? 8 : _mpc.sr;
	_mpc.sr = (*A <= *B) ? 7 : _mpc.sr;
	_mpc.sr = (*A >= *B) ? 9 : _mpc.sr;
	_mpc.sr = (*A == *B) ? 4 : _mpc.sr;
	_mpc.sr = (*A != *B) ? 5 : _mpc.sr;

	_mpc._CVB[6] = (*A < *B) ? 1 : 0;
	_mpc._CVB[8] = (*A > *B) ? 1 : 0;
	_mpc._CVB[7] = (*A <= *B) ? 1 : 0;
	_mpc._CVB[9] = (*A >= *B) ? 1 : 0;
	_mpc._CVB[4] = (*A == *B) ? 1 : 0;
	_mpc._CVB[5] = (*A != *B) ? 1 : 0;
      }
  }
}
