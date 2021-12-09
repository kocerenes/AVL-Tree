hepsi: derle calistir

derle:	
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Person.o -c ./src/Person.cpp
	g++ -I ./include/ -o ./lib/AVLTree.o -c ./src/AVLTree.cpp
	g++ -I ./include/ -o ./lib/NodeOfStack.o -c ./src/NodeOfStack.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Processes.o -c ./src/Processes.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Node.o ./lib/Person.o ./lib/AVLTree.o ./lib/NodeOfStack.o ./lib/Stack.o ./lib/Processes.o ./src/Main.cpp
calistir:
	./bin/test