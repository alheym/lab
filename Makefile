# Compiler
CC=g++
# Flags to compile an object file from source file
CFLAGS=-c
# Flags to compile an executed file from object file
OFLAG=-o
# CppUnit flags
CPPUNIT_FLAGS=-I$CPPUNIT_HOME/include -L$CPPUNIT_HOME/lib -lcppunit
# Output executed file name
OFILE=print_program

all: $(OFILE) test

$(OFILE): Printer.o main.o
	$(CC) Printer.o main.o $(CPPUNIT_FLAGS) $(OFLAG) $(OFILE)

Printer.o: Printer.cpp
	$(CC) $(CFLAGS) Printer.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

test: $(OFILE)
	./$(OFILE) --test

clean:
	rm -rf *.o $(OFILE)