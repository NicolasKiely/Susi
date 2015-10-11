CC=g++ -Wall -g
SK=src/kernel/
OK=obj/kernel/
KOBJS=$(OK)main.o $(OK)context.o $(OK)logger.o $(OK)global_context.o \
	$(OK)settings.o
KHEADERS=$(SK)context.h $(SK)logger.h


# Final binary compiles
bin/susi: $(KOBJS)
	$(CC) $(KOBJS) -o bin/susi


# Clean up temp files
.PHONY: clean
clean:
	rm $(OK)*


# Intermediate kernel object targets
$(OK)main.o: $(SK)main.cc $(KHEADERS)
	$(CC) -c $(SK)main.cc -o $(OK)main.o

$(OK)context.o: $(SK)context.cc $(SK)context.h
	$(CC) -c $(SK)context.cc -o $(OK)context.o

$(OK)logger.o: $(SK)logger.cc $(SK)logger.h
	$(CC) -c $(SK)logger.cc -o $(OK)logger.o

$(OK)global_context.o: $(SK)global_context.cc $(SK)global_context.h
	$(CC) -c $(SK)global_context.cc -o $(OK)global_context.o

$(OK)settings.o: $(SK)settings.cc $(SK)settings.h
	$(CC) -c $(SK)settings.cc -o $(OK)settings.o
