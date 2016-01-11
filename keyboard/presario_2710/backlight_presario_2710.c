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

const uint8_t backlight_pwm_max = 153;
const uint8_t backlight_pwm_min = 63;
const uint8_t backlight_pwm_step = 6;

void backlight_init_ports(void)
{
  // output on OC0A (PB7)
  DDRB |= (1 << PB7);
  
  // Activate PLL and wait for it to lock
  PLLCSR |= (1 << PLLE);
  loop_until_bit_is_set(PLLCSR, PLOCK); 
  
  // Set default PWM value in OCR0A, the saved value will be restored by a call to backlight_set via backlight_init inside keyboard_init
	OCR0A = backlight_pwm_min;

  // Set Fast PWM mode with TOP set to MAX (0xFF) value (WGM2:0 = 3)
  TCCR0B &= ~(1 << WGM02);  
  TCCR0A |= (1 << WGM01) | (1 << WGM00); 
  
  // PLL as clock source, factor 1 prescaler: clear all three CS0x bits then set CS00
  TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
  TCCR0B |= (1 << CS00);
  
  // Type of output: non inverted (10) or inverted (11)
  TCCR0A |= (1 << COM0A1) | (0 << COM0A0); 
}

void backlight_set(uint8_t level)
{
   // set new PWM duty cycle
   // the level is saved in eeprom by the various backlight functions
   OCR0A = backlight_pwm_min + level * backlight_pwm_step;
}

