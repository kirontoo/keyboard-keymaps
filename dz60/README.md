# Kirontoo's DZ60 Keymap
This layout is for the DZ60 with a 60_b_ansi layout.
This includes:
* split spacebar
* split backspace
* split right shift
* 5 1u bottom row modifiers.

``` 
    LAYOUT_60_b_ansi (maximized DZ60 Plate B layout for ANSI)
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0a │0b │0c │0d │0e │  15 KEYS
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
  │10   │12 │13 │14 │15 │16 │17 │18 │19 │1a │1b │1c │1d │1e   │  14 KEYS
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
  │20    │22 │23 │24 │25 │26 │27 │28 │29 │2a │2b │2c │2d      │  13 KEYS
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┬───┤
  │30      │32 │33 │34 │35 │36 │37 │38 │39 │3a │3c    │3d │3e │  13 KEYS
  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬───┼───┼───┤
  │40  │41  │43  │44      │46  │48        │4a │4b │4c │4d │4e │  11 KEYS
  └────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┘
```

## Hardware Info
The DZ60 is a 60% pcb produced by KBDFans. The one I have comes with USB C. For USB C, it does not have a hardware reset switch.

This keyboards ifs uses:
* Layout B
* USB C
* Gateron Browns

## Build
To build this keymap, simply run ```make dz60:kirontoo```


## Layers
This keymap has 6 different layers.


### _QWERTY : QWERTY LAYOUT
This is the base layer (layer 0). It is a standard QWERTY layout with a few custom keycodes.

``` 
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┬─────┬───┐
  │`~ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │-_ │=+  │BSPC │DEL│  
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬─┴─┬───┴───┤
  │TAB  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[{  │]} │\|     │  
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┴┬──┴───────┤
  │LT    │ A │ S │ D │ F │ G │ H │ J │ K │ L │;: │'"  │ENTER     │  
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┴┬────┬────┤
  │LSHIFT  │ Z │ X │ C │ V │ B │ N │ M │,< │.> │RSFT / │UP  │TG  │  
  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬────┼────┼────┤
  │CTRL│WIN │ALT │SPC     │FN1 │BSPC      │FN2│TT │LEFT│DOWN│RGHT│  
  └────┴────┴────┴────────┴────┴──────────┴───┴───┴────┴────┴────┘
```

* The ```PS``` is the print screen key.
* The ```LT``` key will activate layer ```_FN``` on hold and the ```ESC``` key on tap.
* The ```RSFT /``` key will activate right shift on hold and ```/``` on tap.
* The ```FN1``` key will activate layer ```_FL```.
* The ```FN2``` key will activate layer ```_KL```.
* The ```TT``` key will activate layer ```_ML``` on hold and toggles the same layer after 3 taps.
* The ```TG``` key will toggle layer ```_COLEMAK```

### _COLEMAK : COLEMAK LAYOUT
This is the base layer (layer 0). It is a standard QWERTY layout with a few custom keycodes.

``` 
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┬─────┬───┐
  │`~ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │-_ │=+  │BSPC │DEL│  
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬─┴─┬───┴───┤
  │TAB  │ Q │ W │ F │ P │ G │ J │ L │ U │ Y │ : │[{  │]} │\|     │  
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┴┬──┴───────┤
  │LT    │ A │ R │ S │ T │ D │ H │ N │ E │ I │ Y │'"  │ENTER     │  
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┴┬────┬────┤
  │LSHIFT  │ Z │ X │ C │ V │ B │ K │ M │,< │.> │RSFT / │UP  │TG  │  
  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬────┼────┼────┤
  │CTRL│WIN │ALT │SPC     │FN1 │BSPC      │FN2│TT │LEFT│DOWN│RGHT│  
  └────┴────┴────┴────────┴────┴──────────┴───┴───┴────┴────┴────┘
```

### _FL : Utilizes a few symbols.

``` 
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┬─────┬───┐
  │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12 │PAUSE│   │  
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬─┴─┬───┴───┤
  │     │   │   │ = │ + │   │   │ - │ _ │   │   │    │   │       │  
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┴┬──┴───────┤
  │LT    │   │   │ { │ } │ & │ | │ [ │ ] │   │   │    │ENTER     │  
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┴┬────┬────┤
  │        │   │   │   │   │   │   │   │   │   │INSERT │PGUP│DEL │  
  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬────┼────┼────┤
  │    │    │    │        │FN1 │          │FN2│TT │HOME│PGDN│END │  
  └────┴────┴────┴────────┴────┴──────────┴───┴───┴────┴────┴────┘
```

### _FN : F1-F12 and navigation

``` 
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┬─────┬───┐
  │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12 │PAUSE│   │  
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬─┴─┬───┴───┤
  │     │F1 │F2 │F3 │F4 │   │PGU│HM │UP │END│   │    │   │       │  
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┴┬──┴───────┤
  │LT    │F5 │F6 │F7 │F8 │   │PGD│LFT│DWN│RGT│   │    │ENTER     │  
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┴┬────┬────┤
  │        │F9 │F10│F11│F12│   │   │   │   │   │INSERT │PGUP│DEL │  
  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬────┼────┼────┤
  │    │    │    │        │FN1 │          │FN2│TT │HOME│PGDN│END │  
  └────┴────┴────┴────────┴────┴──────────┴───┴───┴────┴────┴────┘
```

### _ML : Media and Lighting Layer
This is the media and lighting layer (layer 2). It utilizes RGB controls and audio keys.
These lighting keymaps are all for the RGB underglow.

``` 
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┬─────┬───┐
  │   │H+ │H- │S+ │S- │M_T│   │   │   │   │TOG│B- │B+  │     │   │  
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬─┴─┬───┴───┤
  │     │   │MSW│   │M_R│   │   │   │   │   │M_P│RMOD│MOD│       │  
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┴┬──┴───────┤
  │LT    │   │M_S│   │   │M_G│   │   │M_K│   │   │    │          │  
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┴┬────┬────┤
  │        │   │M_X│   │   │M_B│   │   │   │   │ MUTE  │VOL+│PLAY│  
  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬────┼────┼────┤
  │    │    │    │        │FN1 │          │FN2│TT │PREV│VOL-│NEXT│  
  └────┴────┴────┴────────┴────┴──────────┴───┴───┴────┴────┴────┘
```

| KEY  | DESCRIPTION         | KEY  | DESCRIPTION         |
|------|---------------------|------|---------------------|
| H+   | Hue +               | RMOD | RGB Mode Reverse    |
| H-   | Hue -               | MOD  | RGB Mode Forward    |
| S+   | Saturation +        | TOG  | RGB Toggle Lighting |
| S-   | Saturation -        | B-   | Brightness -        |
| M_T  | RGB Mode Toggle     | B+   | Brightness +        |
| MSW  | RGB Mode            | MUTE | Mute Audio          |
| M_X  | RGB XMAS            | VOL+ | Volume +            |
| M_R  | RGB Rainbow         | VOL- | Volume -            |
| M_G  | RGB Gradient        | PLAY | Play/Pause Music    |
| M_B  | RGB Breathe         | PREV | Previous Song       |
| M_K  | RGB Knight Rider    | NEXT | Next Song           |
| M_P  | RGB Plain (Static)  |      |                     |

### _KL : Useful Keyboard Shortcuts Layer

``` 
  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┬────┬────┐
  │   │   │   │   │   │   │   │   │   │   │SDN│   │    │    │TSK │  
  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬─┴─┬──┴────┤
  │     │   │   │   │   │   │   │   │   │   │CMD│    │   │       │  
  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┴┬──┴───────┤
  │LT    │   │STM│   │   │   │   │   │   │LCK│   │    │          │  
  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┴┬────┬────┤
  │        │   │   │CLC│VS │BLI│   │   │   │   │       │    │P_M │  
  ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬────┼────┼────┤
  │    │    │    │        │FN1 │          │FN2│TT │    │    │    │  
  └────┴────┴────┴────────┴────┴──────────┴───┴───┴────┴────┴────┘
```
| KEY  | DESCRIPTION         | KEY  | DESCRIPTION         |
|------|---------------------|------|---------------------|
| SDN  | Exit App            | TSK  | Task Manager        |
| LCK  | Lock Screen         | CMD  | Command Prompt      |
| CLC  | Launch Calculator   | STM  | Launch Steam        |
| BLI  | Launch Blizzard App | VS   | Launch VSCode       |
| P_M  | PrintScn one monitor|      |                     |
```
## RGB Lighting
### RGBLIGHT_SLEEP
This is set in `kirontoo/config.h` so that when the computer goes to sleep, the RGB lights will go sleep as well. They will turn back on when the computer wakes back up.
