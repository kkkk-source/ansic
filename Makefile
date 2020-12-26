main: kcol.o main.o anik.o
	gcc -o main kcol.o main.o anik.o -pthread

main.o: main.c
	gcc -c main.c -Wall -Werror

kcol.o: kcol.c
	gcc -c kcol.c -Wall -Werror 

anik.o: anik.c
	gcc -c anik.c -Wall -Werror

cylon: cylon.o
	avr-gcc -g -Os -mmcu=atmega8 -c cylon.c -DF_CPU=1000000UL

fmt:
	find . -type f -name '*.c'  -o -name '*.h'  -exec indent {} \;
	find . -type f -name '*.c~' -o -name '*.h~' -exec rm {} \;
