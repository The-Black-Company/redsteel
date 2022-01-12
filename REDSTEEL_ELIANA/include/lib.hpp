///#include <iostream>
//#include <fstream>
#include <cerrno>
//#include <cstring>
//#include <algorithm>
//#include <string_view>
#include <vector>
#include <cassert>
//#include <string>
#include <cstddef>
#include <map>
#include <stdio.h>
#include <stdint.h>
//#include <sstream>
#include <string.h>


typedef int16_t byte;
typedef uint16_t ubyte;


#include "instruction.hpp"
#include "MicroProcess.hpp"
#include "dot.hpp"







extern MicroProcessorMemory _mpc;
extern bool c;
extern ubyte *ram;
extern const char *tab[32];

extern "C" {
  void set_memory(byte *mem);
  byte *get_register (const char	*name,
		      int		depth);
  void run_device(void);
  void print_ram (void);
  void get_action ();
  void set_action (t_inst inst, ubyte a, ubyte b);
  char getbit(char c, int i);
  void SET (ubyte *A, ubyte *B);
  void ADD (ubyte *A, ubyte *B);
  void SUB (ubyte *A, ubyte *B);
  void AND (ubyte *A, ubyte *B);
  void IOR (ubyte *A, ubyte *B);
  void XOR (ubyte *A, ubyte *B);
  ubyte IF (ubyte cmp, ubyte *A, ubyte *B);
  void DIV (ubyte *A, ubyte *B);
  void MUL (ubyte *A, ubyte *B);
  void SHR (ubyte *A, ubyte *B);
  void SHL (ubyte *A, ubyte *B);
  void COMPARE (ubyte *A, ubyte *B);
}







#define BITREV(data, bit_nbr)    ((data) ^= (1 << (bit_nbr)))
#define BITGET(data, bit_nbr)    ((data) &  (1 << (bit_nbr)))
#define BITSET(data, bit_nbr)    ((data) |= (1 << (bit_nbr)))
#define BITRESET(data, bit_nbr)  ((data) & ~(1 << (bit_nbr)))

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
