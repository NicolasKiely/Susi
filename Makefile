CC=g++ -Wall
KOBJS=obj/kernel/main.o obj/kernel/context.o obj/kernel/logger.o
KHEADERS=src/kernel/context.h src/kernel/logger.h


# Final binary compiles
bin/susi: $(KOBJS)
	$(CC) $(KOBJS) -o bin/susi


# Intermediate kernel object targets
obj/kernel/main.o: src/kernel/main.cc $(KHEADERS)
	$(CC) -c src/kernel/main.cc -o obj/kernel/main.o

obj/kernel/context.o: src/kernel/context.cc src/kernel/context.h
	$(CC) -c src/kernel/context.cc -o obj/kernel/context.o

obj/kernel/logger.o: src/kernel/logger.cc src/kernel/logger.h
	$(CC) -c src/kernel/logger.cc -o obj/kernel/logger.o
