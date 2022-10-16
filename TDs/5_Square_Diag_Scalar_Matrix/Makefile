main.exe: common_defs.h MVector.o Matrix.o SquareMatrix.o DiagonalMatrix.o ScalarMatrix.o main_squarematrix.cpp
	g++ MVector.o Matrix.o SquareMatrix.o DiagonalMatrix.o ScalarMatrix.o main_squarematrix.cpp -o main.exe

MVector.o: MVector.h MVector.cpp
	g++ -c MVector.cpp

Matrix.o: MVector.h Matrix.h Matrix.cpp
	g++ -c Matrix.cpp

SquareMatrix.o: Matrix.h SquareMatrix.h SquareMatrix.cpp
	g++ -c SquareMatrix.cpp

DiagonalMatrix.o: SquareMatrix.h DiagonalMatrix.h DiagonalMatrix.cpp
	g++ -c DiagonalMatrix.cpp

ScalarMatrix.o: SquareMatrix.h ScalarMatrix.h ScalarMatrix.cpp
	g++ -c ScalarMatrix.cpp
