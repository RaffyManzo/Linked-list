all: list.exe

list.exe: list.o item_int.o main.o
	gcc -o list.exe list.o item_int.o main.o

list.o: list.c list.h item.h
	gcc -c list.c

item_int.o: item_int.c item.h
	gcc -c item_int.c

main.o: main.c list.h item.h
	gcc -c main.c

clean:
	rm -f *.o list.exe
