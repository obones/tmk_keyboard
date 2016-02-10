/*
Copyright 2016 Olivier Sannier <obones@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include "stdint.h"
#include "led.h"


// Using an inline method actually saves space in the final image
inline void setLedRegisters(uint8_t usb_led, uint8_t ledBitShift, uint8_t ledPin)
{ 
    if (usb_led & (1<<ledBitShift)) {
        // output low 
        DDRE |= (1<<ledPin);
        PORTE &= ~(1<<ledPin);
    } else {
        // output high
        DDRE |= (1<<ledPin);
        PORTE |= (1<<ledPin);
    }
}
    
void led_set(uint8_t usb_led)
{
    setLedRegisters(usb_led, USB_LED_NUM_LOCK, 0);
    setLedRegisters(usb_led, USB_LED_CAPS_LOCK, 1);
    setLedRegisters(usb_led, USB_LED_SCROLL_LOCK, 6);
}
