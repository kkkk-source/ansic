cylon: cylon.o
	avr-gcc -g -Os -mmcu=atmega8 -c cylon.c -DF_CPU=1000000UL

fmt:
	find . -type f -name '*.c'  -o -name '*.h'  -exec indent {} \;
	find . -type f -name '*.c~' -o -name '*.h~' -exec rm {} \;
