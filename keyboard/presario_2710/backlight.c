/*
Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>

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
#include <avr/eeprom.h>

const uint8_t backlight_pwm_max = 153;
const uint8_t backlight_pwm_min = 63;
const uint8_t backlight_pwm_step = 6;

EEMEM uint8_t backlight_pwm_value;

void backlight_init_ports(void)
{
  // output on OC0A (PB7)
  DDRB |= (1 << PB7);
  
  // Activate PLL and wait for it to lock
  PLLCSR |= (1 << PLLE);
  while (!(PLLCSR & PLOCK)) 
    ; 
  
  // Set saved PWM value in OCR0A
	OCR0A = eeprom_read_byte(&backlight_pwm_value);

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
   // set and save new PWM duty cycle
   uint8_t newPWM = backlight_pwm_min + level * backlight_pwm_step;
   OCR0A = newPWM;
   eeprom_write_byte(&backlight_pwm_value, newPWM);                                                 
}

