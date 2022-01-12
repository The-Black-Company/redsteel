#include	"redsteel.rs"
#include	"video.rs"

set_label_start	CARTRIDGE

#define		LAYERW		1350
#define		LAYER0_C0	FIRST_LAYER
#define		LAYER0_C1	0x8031
#define		LAYER0_C2	0x8032
#define		LAYER0_C3	0x8033
#define		LAYER0_PIXELS	0x8034

; 0x8030 + 1350 + 4
#define		LAYER1_C0	0x857A
#define		LAYER1_C1	0x857B
#define		LAYER1_C2	0x857C
#define		LAYER1_C3	0x857D
#define		LAYER1_PIXELS	0x857E

; On définie la taille de l'écran
  CAL init_screen

; On défini rouge comme étant la couleur 0 du plan 0
  SET RED, LAYER0_C0
  SET #0, O0
  SET #LAYER0_PIXELS, O1
  SET #LAYERW, O2
  CAL fill_screen

; On défini bleu comme étant la couleur 0 du plan 1
  SET BLUE, LAYER1_C0
  SET #0, O0
  SET #LAYER1_PIXELS, O1
  SET #LAYERW, O2
  CAL fill_screen
; On travaille le clignotement
blink:
  SET #1, VIDEO_LAYER
  SET #100, O0
  CAL wait
  SET #2, VIDEO_LAYER
  SET #100, O0
  CAL wait
  SET blink, PC ; Boucle infinie

init_screen:
  ; 120 * 90 / 8 = 1350
  ; soit 6 couches disponible (8100 de consommation)

  SET 120, $VIDEO_WIDTH ; On définie la largeur de la fenetre
  SET 90, $VIDEO_HEIGHT ; On définie la hauteur de la fenetre
  SET 0, $VIDEO_LAYER ; Aucune couche n'est affiché
  RET

fill_screen:
  ; parametre 0: couleur
  ; parametre 1: position
  ; parametre 2: taille
  ADD I1, I2
fill_screen_loop:
  SET I0, L0
  SET 0, (I1)

  ; Pose de 8 pixels
  IOR L0, (I1)
  SH< 2, L0
  IOR L0, (I1)
  SH< 2, L0
  IOR L0, (I1)
  SH< 2, L0
  IOR L0, (I1)
  SH< 2, L0

  IOR L0, (I1)
  SH< 2, L0
  IOR L0, (I1)
  SH< 2, L0
  IOR L0, (I1)
  SH< 2, L0
  IOR L0, (I1)
  SH< 2, L0

  ADD 1, I1

  CMP I1, I2
  IF< fill_screen_loop
RET

wait:
  ; parametre 0: nombre de cycle
  CMP I0
  IFZ end_wait
  SUB 1, I0
  SET wait, PC
end_wait:
  RET
