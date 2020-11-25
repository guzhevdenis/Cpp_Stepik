CC = g++

CFLAGS = -Wall -std=c++11 -fpermissive

all: array

array:
	$(CC) $(CFLAGS) array.cpp -o array
vector:
	$(CC) $(CFLAGS) vector.cpp -o vector
list:
	$(CC) $(CFLAGS) list.cpp -o list
list_max:
	$(CC) $(CFLAGS) list_max.cpp -o list_max
set:
	$(CC) $(CFLAGS) set.cpp -o set
map:
	$(CC) $(CFLAGS) map.cpp -o map
multimethod:
	$(CC) $(CFLAGS) multimethod.cpp -o multimethod
clean:
	  rm -rf *o test