
extern "C" {
  struct LocalRegisters
  {
    ubyte inputs[8]; // R8 a R15
    ubyte local[8]; // R16 a R23
    // ubyte output[0]; // VIRTUEL ! R24 a R31
  };

  struct MicroProcessorMemory
  {
    union
    {
      ubyte globals[8]; // "R0" a "R7"
      struct
      {
	ubyte pc; // R0 ou PC
	ubyte sr; // Contient tous les bits d'états
	ubyte sp;
	ubyte g[5];
      };
    };
    LocalRegisters local[128];
    ubyte _CVB[11];
  };


}

