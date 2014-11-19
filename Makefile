CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=graphGen.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=graphGen

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) -I ./ $(LDFLAGS) $(OBJECTS) -o $@ -std=c++11

.cpp.o:
	$(CC) -I ./ $(CFLAGS) $< -o $@ -std=c++11


