# Makefile for dev folder

TARGET=search56789

$(TARGET) : $(TARGET).cxx
	g++ -std=c++17 $(TARGET).cxx millerrabin.o -o ../bin/$(TARGET)

construct : construct.cxx
	g++ -std=c++17 -g construct.cxx -o ../bin/cons
	
millerrabin.o : millerrabin.cxx
	g++ -std=c++17 -c millerrabin.cxx
	
