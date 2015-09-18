CC=gcc -Wall -std=c99
OBJS=obj/kernel/main.o obj/kernel/context.o

# Final binary compiles
bin/susi: $(OBJS)
	$(CC) $(OBJS) -o bin/susi

# Intermediate kernel object targets
obj/kernel/main.o: src/kernel/main.c src/kernel/settings.h src/kernel/context.h
	$(CC) -c src/kernel/main.c -o obj/kernel/main.o

obj/kernel/context.o: src/kernel/context.c src/kernel/context.h src/kernel/registry.h
	$(CC) -c src/kernel/context.c -o obj/kernel/context.o
