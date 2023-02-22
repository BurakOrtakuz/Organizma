derlebaglacalistir: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Cell.cpp -o ./lib/Cell.o
	g++ -c -I "./include" ./src/Tissue.cpp -o ./lib/Tissue.o
	g++ -c -I "./include" ./src/QueueNode.cpp -o ./lib/QueueNode.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/BstNode.cpp -o ./lib/BstNode.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/SystemNode.cpp -o ./lib/SystemNode.o
	g++ -c -I "./include" ./src/System.cpp -o ./lib/System.o
	g++ -c -I "./include" ./src/OrgNode.cpp -o ./lib/OrgNode.o
	g++ -c -I "./include" ./src/Organism.cpp -o ./lib/Organism.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++ ./lib/Cell.o ./lib/Tissue.o ./lib/QueueNode.o ./lib/Queue.o ./lib/Radix.o ./lib/BstNode.o ./lib/Organ.o ./lib/SystemNode.o ./lib/System.o ./lib/OrgNode.o ./lib/Organism.o ./lib/main.o -o ./bin/program.exe
calistir:
	./bin/program.exe