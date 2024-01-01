# Makefile for dev folder

#----------------------------------------------------------------
TARGET=primes56789

$(TARGET) : $(TARGET).cxx
	g++ -g -std=c++17 $(TARGET).cxx millerrabin.o -o ../bin/$(TARGET)
	
millerrabin.o : millerrabin.cxx
	g++ -std=c++17 -c millerrabin.cxx
	
#----------------------------------------------------------------
construct : construct.cxx
	g++ -std=c++17 -g construct.cxx -o ../bin/cons
	
