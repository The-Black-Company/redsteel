#include	"redsteel.rs"
#include	"video.rs"

set_label_start CARTRIDGE

; Une image de 1 pixel sur 1, affichee
SET #1, $VIDEO_WIDTH
SET #1, $VIDEO_HEIGHT
SET #0, $VIDEO_LAYER

SET RED, $0x8030 ; On place rouge comme couleur 0
SET #0, $0x8034 ; On place l'unique pixel a la couleur 0...

SET GREEN, $0x8035 ; On place vert comme couleur 0
SET #0, $0x8039 ; On place l'unique pixel a la couleur 0...

SET BLUE, $0x803A ; On place bleu comme couleur 0
SET #0, $0x803E ; On place l'unique pixel a la couleur 0...

loop:
SET #1, $VIDEO_LAYER
SET #2, $VIDEO_LAYER
SET #4, $VIDEO_LAYER
SET loop, PC
