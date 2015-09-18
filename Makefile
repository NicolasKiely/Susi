CC=gcc -Wall -std=c99
OBJS=obj/kernel/main.o obj/kernel/context.o obj/kernel/registry.o
KHEADERS=src/kernel/context.h src/kernel/registry.h src/kernel/settings.h

# Final binary compiles
bin/susi: $(OBJS)
	$(CC) $(OBJS) -o bin/susi

# Intermediate kernel object targets
obj/kernel/main.o: src/kernel/main.c $(KHEADERS)
	$(CC) -c src/kernel/main.c -o obj/kernel/main.o

obj/kernel/context.o: src/kernel/context.c $(KHEADERS)
	$(CC) -c src/kernel/context.c -o obj/kernel/context.o

obj/kernel/registry.o: src/kernel/registry.c $(KHEADERS)
	$(CC) -c src/kernel/registry.c -o obj/kernel/registry.o
