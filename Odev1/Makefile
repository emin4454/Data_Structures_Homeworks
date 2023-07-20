all:derle bagla calistir
derle:
		g++ -c -I "./include" "./src/main.cpp"  -o ./lib/main.o
		g++ -c -I "./include" "./src/linkedlist.cpp" -o ./lib/linkedlist.o
		g++ -c -I "./include" "./src/node.cpp" -o ./lib/node.o
		g++ -c -I "./include" "./src/arraylist.cpp" -o ./lib/arraylist.o
		g++ -c -I "./include" "./src/texttolists.cpp" -o ./lib/texttolists.o

bagla:
		g++ ./lib/linkedlist.o ./lib/main.o ./lib/node.o ./lib/arraylist.o ./lib/texttolists.o -o ./bin/Node.exe
calistir:
		./bin/Node.exe