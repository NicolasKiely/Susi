CC=gcc -std=c99 -Wall -pedantic -g
VG=valgrind --leak-check=yes --error-exitcode=1

# Directory shorthand. S_=sources, O_=objects,
#   T_=tests, TX_=test binaries
SK=src/kernel/
OK=obj/kernel/
TK=test/kernel/
TXK=test/kernel/bin/
KOBJS=$(OK)main.o $(OK)kstring.o
KHEADERS=$(SK)kstring.h
KTESTS=$(TXK)kstring.pass



###############################################################################
# Primary targets                                                             #
###############################################################################

bin/susi: $(KOBJS) $(KTESTS)
	$(CC) $(KOBJS) -o bin/susi



###############################################################################
# Misc and Phony Targets                                                      #
###############################################################################

# Clean up temp files
.PHONY: clean tests
clean:
	rm $(OK)*
	rm $(TXK)*

tests: $(KTESTS)


###############################################################################
# Testing Binaries                                                            #
###############################################################################

$(TXK)kstring.pass: $(TK)kstring.c $(OK)kstring.o $(KHEADERS)
	$(CC) -o $(TXK)kstring $(TK)kstring.c $(OK)kstring.o
	$(VG) $(TXK)kstring



###############################################################################
# Intermediate files                                                          #
###############################################################################

$(OK)main.o: $(SK)main.c $(KHEADERS)
	$(CC) -c $(SK)main.c -o $(OK)main.o

$(OK)kstring.o: $(SK)kstring.c $(KHEADERS)
	$(CC) -c $(SK)kstring.c -o $(OK)kstring.o
