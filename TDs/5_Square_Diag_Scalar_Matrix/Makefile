CXX = g++
CXXFLAGS = -W -Wall -std=c++11

objects = main_squarematrix.o Matrix.o MVector.o SquareMatrix.o DiagonalMatrix.o ScalarMatrix.o

main: $(objects)
	$(CXX) $(CFLAGS) -o main_squarematrix $(objects)
$(objects): common_defs.h
main.o matrix.o MVector.o SquareMatrix.o DiagonalMatrix.o ScalarMatrix.o: MVector.h

all: main

clean:
	rm main_squarematrix $(objects)