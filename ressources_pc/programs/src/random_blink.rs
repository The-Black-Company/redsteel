#include	"redsteel.rs"
#include	"video.rs"

set_label_start CARTRIDGE

; Une image de 1 pixel sur 1, affichee
SET #1, $VIDEO_WIDTH
SET #1, $VIDEO_HEIGHT
SET #0, $0x8034
SET #1, $VIDEO_LAYER

loop:
; Random dans le champ couleur 0
SET $KEYBOARD, L0
SET $KEYBOARD, $0x8030
SET loop, PC
