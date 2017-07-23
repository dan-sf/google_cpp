CC = c++

all: main

composer.o: composer.cpp
	$(CC) -c composer.cpp

database.o: database.cpp
	$(CC) -c database.cpp

test_database: composer.o database.o
	$(CC) composer.o database.o test_database.cpp -o test_database

test_composer: composer.o database.o
	$(CC) composer.o test_composer.cpp -o test_composer

main: composer.o database.o
	$(CC) composer.o database.o composer_main.cpp -o composer_main

clean:
	rm -f core *.o *~

