




#pragma pack (1)
typedef struct s_instruction
{
  unsigned int ni : 6;
  unsigned int fam : 2;
  unsigned int fm : 3;
  unsigned int sam : 2;
  unsigned int sm : 3;
}	t_instruction;
#pragma pack (0)

typedef union s_inst
{
  ubyte  ram;
  t_instruction inst;
}	      t_inst;

