#include <avr/io.h>
#include <util/delay.h>

#define DELAYTIME 85

int
main (void)
{
  uint8_t i;
  DDRB = 0xff;

  i = 0;
  for (;;)
    {
      while (i < 7)
	{
	  PORTB = (1 << i);
	  _delay_ms (DELAYTIME);
	  i += 1;
	}
      while (i > 0)
	{
	  PORTB = (1 >> i);
	  _delay_ms (DELAYTIME);
	  i -= 1;
	}
    }
  return 0;
}
