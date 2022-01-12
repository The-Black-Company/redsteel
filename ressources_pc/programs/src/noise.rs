#include "redsteel.rs"
#include "video.rs"

set_label_start CARTRIDGE

SET #32, $VIDEO_WIDTH
SET #32, $VIDEO_HEIGHT
SET #15, $VIDEO_LAYER ; 4 couches

start:

SET #0x8030, L0
; Couleurs aléatoires de la couche 1
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++

SET L0, L1
ADD #128, L1
layer0:
  SET $KEYBOARD, (L0)++
  CMP L0, L1
  IF< layer0

; Couleurs aléatoires de la couche 2
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++

SET L0, L1
ADD #128, L1
layer1:
  SET $KEYBOARD, (L0)++
  CMP L0, L1
  IF< layer1

; Couleurs aléatoires de la couche 3
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++

SET L0, L1
ADD #128, L1
layer2:
  SET $KEYBOARD, (L0)++
  CMP L0, L1
  IF< layer2

; Couleurs aléatoires de la couche 4
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++
SET $KEYBOARD, (L0)++

SET L0, L1
ADD #128, L1
layer3:
  SET $KEYBOARD, (L0)++
  CMP L0, L1
  IF< layer3

SET #start, PC
