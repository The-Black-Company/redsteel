#include	"redsteel.rs"
#include	"video.rs"

set_label_start CARTRIDGE

; Une image de 1 pixel sur 1, affichee
SET #1, $VIDEO_WIDTH
SET #1, $VIDEO_HEIGHT
SET #1, $VIDEO_LAYER
SET BLUE, $FIRST_LAYER ; On place rouge comme couleur 0
SET #0, $0x8034 ; On place l'unique pixel a la couleur 0...

loop:
SET loop, PC
