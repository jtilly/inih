CCFLAGS = -O0 -g -Wall

default: INIReaderTest.out

INIReaderTest.out: INIReaderTest.cpp
	g++ $(CCFLAGS) $< -o $@

clean:
	rm -rf *.o *.out
