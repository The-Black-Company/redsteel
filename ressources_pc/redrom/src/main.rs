
  #include "redsteel.rs"

  ; On saute à la cartouche dès l'adresse 0
  SET #CARTRIDGE, PC

  ; Les outils du BIOS
  ; La table des caractères:
  #include "ascii.rs"

  set_position 420
  memset: ; (byte *data, byte len, byte value)
    ADD I0, I1 ; len = len + data
      memset_loop:
      CMP I0, I1
      IF>= memset_end_loop
        SET I2, (I0)++
      SET memset_loop, PC
    memset_end_loop:
    RET

  set_position 440
  memcpy: ; (byte *dest, byte *src, byte len)
    ADD I0, I2 ; len = len + a
      memcpy_loop:
        CMP I0, I2
	IF>= memcpy_end_loop
	  SET (I1)++, (I0)++
	SET memcpy_loop, PC
    memcpy_end_loop:
    RET
