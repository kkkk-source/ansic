main: kcol.o main.o
	gcc -o main kcol.o main.o -pthread

main.o: main.c
	gcc -c main.c -Wall -Werror

kcol.o: kcol.c
	gcc -c kcol.c -Wall -Werror 
