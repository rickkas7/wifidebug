## Particle Photon Wi-Fi debugging tool

This tool is used to help debug stubborn Wi-Fi connection problems, typically where you get stuck at blinking green.

You must have a working [Particle CLI] (https://particle.io/cli) installation before proceeding. The link above has links to the Windows installer and instructions for Mac and Linux if necessary.

## Install the debugging firmware

Download the wifidebug.bin file. 

Put the Photon in DFU mode (blinking yellow) by holding down the RESET and SETUP buttons, then release RESET. Continue to hold down SETUP while it blinks magenta until it blinks yellow, then release.

Then use the command:

```
particle flash --usb wifidebug.bin
```

The Photon should go into breathing blue mode.

## Monitor the output

Use the command:

```
paricle serial monitor
```

It should print out the currently configured credentials (without passwords) and any Wi-Fi networks in range along with their channel numbers, encryption types and signal strength (RSSI). It will repeat every 10 seconds.

Copy and paste this information and include it in your support ticket.

## Restore normal firmware

Put the Photon in DFU mode (blinking yellow) by holding down the RESET and SETUP buttons, then release RESET. Continue to hold down SETUP while it blinks magenta until it blinks yellow, then release.

Then issue the command:

```
particle flash --usb tinker
```

