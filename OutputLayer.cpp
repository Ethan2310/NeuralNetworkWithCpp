#include "OutputLayer.h"
#include <iostream>
#include <cstdlib>
using namespace std;

OutputLayer::OutputLayer(int numweight, double * weight)
{
    numWeights = numweight;
    weights = weight;
    outputValue = 0.0;
}

OutputLayer::~OutputLayer()
{
    delete [] weights;
    weights = NULL;

    // cout << "OL destroyed\n";
}

double OutputLayer::getOutputValue()
{
    return outputValue;
}

void OutputLayer::setOutputValue(double outputval)
{
    outputValue = outputval;
}

void OutputLayer::forward(HiddenLayer* lastHiddenLayer) //double check this
{
    double product = 0.0;
    outputValue = 0.0;

    HiddenNeuron ** lastArray = lastHiddenLayer->getNeurons();

    for (int i = 0; i < lastHiddenLayer->getNumNeurons(); i++)
        product = product + (lastArray[i]->getValue() * weights[i]);

    outputValue = product;

    lastArray = NULL; 
}

void OutputLayer::printLayer()
{
    cout << "o:1" << endl;
}

void OutputLayer::clearLayer()
{
    outputValue = 0.0;
}