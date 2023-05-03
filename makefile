run: main
	./main

main: main.o InputLayer.o HiddenNeuron.o HiddenLayer.o OutputLayer.o NeuralNetwork.o
	g++ -o main main.o InputLayer.o HiddenNeuron.o HiddenLayer.o OutputLayer.o NeuralNetwork.o

main.o:	main.cpp
	g++ -c -w -std=c++98 main.cpp

InputLayer.o:	InputLayer.cpp
	g++ -c -w -std=c++98 InputLayer.cpp

HiddenNeuron.o:	HiddenNeuron.cpp
	g++ -c -w -std=c++98 HiddenNeuron.cpp

HiddenLayer.o:	HiddenLayer.cpp
	g++ -c -w -std=c++98 HiddenLayer.cpp

OutputLayer.o:	OutputLayer.cpp
	g++ -c -w -std=c++98 OutputLayer.cpp

NeuralNetwork.o:	NeuralNetwork.cpp
	g++ -c -w -std=c++98 NeuralNetwork.cpp

clean:
	rm *.o main
