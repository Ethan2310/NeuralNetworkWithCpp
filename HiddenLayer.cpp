#include "HiddenLayer.h"
#include <iostream>
#include <cstdlib>
using namespace std;

HiddenLayer::HiddenLayer(int numneuron, HiddenNeuron** neuron, string activate = "")
{
    numNeurons = numneuron;
    neurons = neuron;
    activation = activate;
}

HiddenLayer::~HiddenLayer()
{
    for (int i = 0; i < numNeurons; i++)
        delete neurons[i];
    delete [] neurons;
    neurons = NULL;

    // cout << "HL destroyed\n";
}

HiddenNeuron** HiddenLayer::getNeurons()
{
    return neurons;
}

void HiddenLayer::setNeurons(HiddenNeuron** neuron)
{
    if (neurons == NULL)
        neurons = neuron;

    else if (neurons != NULL)
    {
        for (int i = 0; i < numNeurons; i++)
            delete neurons[i];
        delete [] neurons;
        neurons = NULL;
        neurons = neuron;
    }
}

int HiddenLayer::getNumNeurons()
{
    return numNeurons;
}

void HiddenLayer::setNumNeurons(int numneuron)
{
    numNeurons = numneuron;
}

void HiddenLayer::forward(HiddenLayer* prevLayer)
{
    for (int i = 0; i < numNeurons; i++)
    {
        neurons[i]->forward(prevLayer);
        
        if (activation == "relu")
            neurons[i]->activateReLU();
        else if (activation == "sigmoid")
            neurons[i]->activateSigmoid();
    }
}

void HiddenLayer::forward(InputLayer* inputLayer)
{
    for (int i = 0; i < numNeurons; i++)
    {
        neurons[i]->forward(inputLayer);
        
        if (activation == "relu")
            neurons[i]->activateReLU();
        else if (activation == "sigmoid")
            neurons[i]->activateSigmoid();
    }
}

void HiddenLayer::printLayer()
{
    cout << "h:" << numNeurons << ":" << activation << endl;
}

void HiddenLayer::clearLayer()
{
    if (neurons != NULL)
    {
        for (int i = 0; i < numNeurons; i++)
            neurons[i]->setValue(0.0);
    }
}