all:derle bagla calistir
derle:
		g++ -c -I "./include" "./src/main.cpp"  -o ./lib/main.o
		g++ -c -I "./include" "./src/doublyLinkedList.cpp" -o ./lib/doublyLinkedList.o
bagla:
		g++ ./lib/doublyLinkedList.o ./lib/main.o -o ./bin/doublyNode.exe
calistir:
		./bin/doublyNode.exe