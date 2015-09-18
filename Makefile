CC=gcc -Wall -std=c99

# Final binary compiles
bin/susi: obj/kernel/main.o
	$(CC) obj/kernel/main.o -o bin/susi

# Intermediate kernel object targets
obj/kernel/main.o: src/kernel/main.c
	$(CC) -c src/kernel/main.c -o obj/kernel/main.o
