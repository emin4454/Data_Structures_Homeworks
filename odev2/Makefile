all:derle bagla calistir
derle:
		g++ -c -I "./include" "./src/main.cpp"  -o ./lib/main.o  
		g++ -c -I "./include" "./src/stack.cpp" -o ./lib/stack.o 
		g++ -c -I "./include" "./src/node.cpp" -o ./lib/node.o 
		g++ -c -I "./include" "./src/treenode.cpp" -o ./lib/treenode.o  
		g++ -c -I "./include" "./src/binarysearchtree.cpp" -o ./lib/binarysearchtree.o 
		g++ -c -I "./include" "./src/numberreader.cpp" -o ./lib/numberreader.o 

bagla:
		g++ ./lib/stack.o ./lib/main.o ./lib/node.o ./lib/treenode.o ./lib/binarysearchtree.o ./lib/numberreader.o -o ./bin/program.exe
calistir:
		 ./bin/program.exe