#include	"redsteel.rs"
#include	"video.rs"

set_label_start CARTRIDGE

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
  SET #'8', O0 ; Le caractère
  SET #5, O1 ; La position en X
  SET #1, O2 ; La position en Y
  CAL wchar

getpixel: ; (p, x, y, w)
  SET I2, L0 ; On met y dans L0
  MUL I3, L0 ; On multiple y par w
  ADD I1, L0 ; On ajoute X
  SET L0, L1 ; On copie la position dans L1
  DIV #8, L0 ; On a le numero du byte dans L0
  SET L0, L2 ; On copie le numero du byte dans L2
  MUL #8, L2 ; On multiplie par 8 pour voir sil y avait un reste
  SET L1, L3 ; On met le max dans L3
  SUB L2, L3 ; On a le reste: un couple de bit dans L3
  ADD I0, L0 ; On ajoute l'adresse de l'image au numero du pixel
  SET (L0), L0 ; On récupère le pixel
  SH> L3, L0 ; On décale pour se mettre face aux 2 bits
  AND #3, L0 ; On filtre tous les autres bits
  SET L0, I0 ; On renvoi la couleur
  RET

setpixel: ; (p, x, y, w, c)
  SET I2, L0 ; On met y dans L0
  MUL I3, L0 ; On multiple y par w
  ADD I1, L0 ; On ajoute X
  SET L0, L1 ; On copie la position dans L1
  DIV #8, L0 ; On a le numero du byte dans L0
  SET L0, L2 ; On copie le numero du byte dans L2
  MUL #8, L2 ; On multiplie par 8 pour voir sil y avait un reste
  SET L1, L3 ; On met le max dans L3
  SUB L2, L3 ; On a le reste: un couple de bit dans L3
  MUL #2, L3 ; 2 bits par couleur
  ADD I0, L0 ; On ajoute l'adresse de l'image au numero du pixel
  SH< L3, I4 ; On aligne la couleur correctement
  IOR I4, (L0) ; On colle la couleur allignée sur le byte contenant le pixel
  RET

wchar:
  ; Les pixels font 5 de large et 7 de haut
  SET #LAYER0_PIXELS, O0
  SET #1, O1
  SET #1, O2
  SET #120, O3
  SET #3, O4
  CAL setpixel
  SET wchar, PC

init_screen:
  ; 120 * 90 / 8 = 1350
  ; soit 6 couches disponible (8100 de consommation)

  SET 120, $VIDEO_WIDTH ; On définie la largeur de la fenetre
  SET 90, $VIDEO_HEIGHT ; On définie la hauteur de la fenetre
  ; On définie le noir comme couleur 0, puis des nuances de rouge puis rouge pour 3.
  ; On remplit l'ecran de noir

  SET BLACK, LAYER0_C0
  SET 0x0005, LAYER0_C1
  SET 0x000A, LAYER0_C2
  SET RED, LAYER0_C3
  SET #0, $FILL_COLOR0
  SET #1, $FILL_LAYER
  SET #1, $VIDEO_LAYER ; On affiche la couche 1

  RET
