Presario 2710 keyboard firmware
======================
Reusing the eyboard from a dead Presario 2710 laptop.

## GH60 Resources

## Build
Move to this directory then just run `make` like:

    $ make
    
As I work under Windows, I created the build.bat batch file to call the proper MinGW/MSys executables. 

## Keymap
Only the French keymap (AZERTY) is available, as it is the one physcally present on the board. 

### 1  Presario 2710
[keymap_presario_2710.c](keymap_presario_2710.c) emulates original Presario 2710 layers

NOTE: LAYER is still to be determined, the following ones are from the GH60

#### 1.0 Default layer
    ,-----------------------------------------------------------.
    |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
    |-----------------------------------------------------------|
    |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
    |-----------------------------------------------------------|
    |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
    |-----------------------------------------------------------|
    |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
    |-----------------------------------------------------------|
    |Ctrl|Gui |Alt |      Space             |Fn  |Gui |App |Ctrl|
    `-----------------------------------------------------------'
#### 1.1 Fn layer
    ,-----------------------------------------------------------.
    |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |
    |-----------------------------------------------------------|
    |     |FnQ| Up|   |   |   |   |   |   |Cal|   |Hom|Ins|     |
    |-----------------------------------------------------------|
    |      |Lef|Dow|Rig|   |   |Psc|Slk|Pau|   |Tsk|End|        |
    |-----------------------------------------------------------|
    |        |Del|   |Web|Mut|VoU|VoD|   |PgU|PgD|Del|   Up     |
    |-----------------------------------------------------------|
    |    |    |    |         FnS            |Fn  |Left|Down|Righ|
    `-----------------------------------------------------------'


