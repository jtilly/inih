CCFLAGS = -O0 -g -Wall

default: INIReaderTest.out

INIReader.o: INIReader.cpp
	g++ $(CCFLAGS) -c $< -o $@

INIReaderTest.out: INIReaderTest.cpp INIReader.o
	g++ $(CCFLAGS) INIReaderTest.cpp INIReader.o -o $@

clean:
	rm -rf *.o *.out
