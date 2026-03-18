# QMK Firmware for a 3x5 + 3 Keyboard

This is my QMK firmware that should work with any split keyboard that has 15 standard and 3 thumb
keys per side (36 keys total).

## Instructions

1. Install the QMK toolchain:

```bash
$ python -m venv qmk_env
$ source qmk_env/bin/activate
$ pip install qmk
```

2. Clone QMK and this repo:

```bash
$ qmk clone
$ git clone git@github.com:alfred-hodler/endgame.git
$ export KEYBOARD=beekeeb/3w6hs # change this as needed
$ ln -s $(readlink -f endgame) qmk_firmware/keyboards/$KEYBOARD/keymaps/endgame
```

3. Compile:

```bash
$ qmk compile -kb $KEYBOARD -km endgame
# The compiled firmware is now in the qmk_firmware directory
```
