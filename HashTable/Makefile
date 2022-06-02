all: chained_hashtest

chained_hashtest: chained_hashtable.o linked_list.o
	gcc -o chained_hashtest chained_hashtest.c chained_hashtable.o linked_list.o

chained_hashtable.o: chained_hashtable.c chained_hashtable.h linked_list.h
	gcc -c chained_hashtable.c

linked_list.o: linked_list.c linked_list.h 
	gcc -c linked_list.c

clean:
	rm *.o chained_hashtest