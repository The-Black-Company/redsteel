#include	"redsteel.rs"
#include	"video.rs"

set_label_start CARTRIDGE

SET #0, $VIDEO_LAYER ; Mise à zéro des couches affichés pour éviter le bruit initial
SET #20, $VIDEO_WIDTH
SET #20, $VIDEO_HEIGHT

SET RED, $0x8030
SET GREEN, $0x8031
SET BLUE, $0x8032
SET WHITE, $0x8033

SET #0, L0

set_clear:
  SET L0, $FILL_COLOR0
  SET #1, $FILL_LAYER
  SET #1, $VIDEO_LAYER
  ADD #1, L0
  AND #0b11, L0

wait_ready:
  CMP $VIDEO_READY
  IFZ set_clear, wait_ready