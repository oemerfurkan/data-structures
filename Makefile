compile-graph:
	mkdir -p ./build/test
	g++ -std=c++23 -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -o ./build/test/graph ./structures/graph/graph.cpp ./test/graph.test.cpp
	./build/test/graph
clean-graph:
	rm -rf ./build/test/graph

compile-dgraph:
	mkdir -p ./build/test
	g++ -std=c++23 -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system -o ./build/test/directed-graph ./structures/graph/directed-graph.cpp ./test/directed-graph.test.cpp
	./build/test/directed-graph
clean-dgraph:
	rm -rf ./build/test/graph