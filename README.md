# qmk_setups
Contains the folders for my qmk setups

# For running QMK in Linux

# You must first *build* the config by giving the path to keymap dir
```bash
cd ~/qmk_firmware 
make massdrop/thekey_v2:default 
```
default is the name of the directory of your specified keymap.c file
for us, this is what it would look like

`make massdrop/thekey_v2:personal`

# Next, you flash the keyboard

 - Bootmagic Reset: Hold down the "Stack Overflow" key, the "left-most" or furthest from the USB plug while inserting the USB cable for a few seconds. The LEDs will NOT turn on.
 - Physical Reset Button: Press the reset button while plugging into USB port.

 ```bash
 make massdrop/thekey_v2:personal:dfu
 ```

