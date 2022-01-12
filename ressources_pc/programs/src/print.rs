#include	"redsteel.rs"
#include	"video.rs"

set_label_start CARTRIDGE

SET #hello, L0
SET #0x6800, L1
SET (L0), L7
SET (L0)++, (L1)++
SET (L0)++, (L1)++
SET (L0)++, (L1)++
SET (L0)++, (L1)++
SET (L0)++, (L1)++
SET (L0)++, (L1)++
SET (L0)++, (L1)++
SET #0, $0x6900
SET #14, $0x6901
loop:
SET #loop, PC

hello:
data "Hello, world!\n"
