demo: demo.o linkedlistfunctions.o linkedlist.h
	gcc -o demo demo.o linkedlistfunctions.o -I.
	make clean

demo.o: demo.c linkedlist.h
	gcc -c -o demo.o demo.c -I.

linkedlistfunctions.o: linkedlistfunctions.c linkedlist.h
	gcc -c -o linkedlistfunctions.o linkedlistfunctions.c -I.

debug: demo.c linkedlistfunctions.c linkedlist.h
	gcc -g -o debug demo.c linkedlistfunctions.c -I.

clean:
	rm *.o
