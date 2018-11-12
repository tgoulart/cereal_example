
all: helloworld

helloworld: helloworld.cpp definitions.hpp serialization.hpp
	clang++ -std=c++14 -g -o helloworld helloworld.cpp -I./cereal/include

clean:
	rm helloworld
