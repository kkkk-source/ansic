#include <avr/io.h>
#include <util/delay.h>

#define DELAYTIME 85

int
main (void)
{
  uint8_t i, whichLED, random;

  random = 0x1234;
  DDRB = 0xff;

  while (1)
    {
      for (i = 0; i < 8; i++)
	{
	  PORTB |= (1 << i);
	  _delay_ms (DELAYTIME);
	}
      for (i = 0; i < 8; i++)
	{
	  PORTB &= ~(1 << i);
	  _delay_ms (DELAYTIME);
	}
      _delay_ms (5 * DELAYTIME);

      for (i = 7; i < 255; i--)
	{
	  PORTB |= (1 << i);
	  _delay_ms (DELAYTIME);
	}

      for (i = 7; i < 255; i--)
	{
	  PORTB |= (1 << i);
	  _delay_ms (DELAYTIME);
	}
      _delay_ms (5 * DELAYTIME);

      for (i = 0; i < 75; i++)
	{
	  random = 2053 * random + 13849;
	  whichLED = (random >> 8) & 0b00000111;
	  PORTB ^= (1 << whichLED);
	  _delay_ms (DELAYTIME);
	}
      PORTB = 0;
      _delay_ms (5 * DELAYTIME);
    }
  return 0;
}
