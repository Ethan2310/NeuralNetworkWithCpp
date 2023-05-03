#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include <string>
#include "InputLayer.h"
#include "HiddenNeuron.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"

class NeuralNetwork
{
    private:
        InputLayer * inputLayer;
        int numHiddenLayers;
        HiddenLayer ** hiddenLayers;
        OutputLayer * outputLayer;

    public:
        NeuralNetwork(std::string);
        ~NeuralNetwork();       
        double forward(double *);
        void printNetwork();
        void clearNetwork();
};

#endif