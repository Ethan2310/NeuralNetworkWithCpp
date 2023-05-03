#include "HiddenNeuron.h"
#include "HiddenLayer.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

HiddenNeuron::HiddenNeuron(int numweight, double * weight)
{
    numWeights = numweight;
    weights = weight;
    value = 0.0;
}

HiddenNeuron::~HiddenNeuron()
{
    delete [] weights;
    weights = NULL;

    // cout << "HN destroyed\n";
}

double HiddenNeuron::getValue()
{
    return value;
}

void HiddenNeuron::setValue(double val)
{
    value = val;
}

void HiddenNeuron::forward(HiddenLayer* prevlayer)
{
    double product = 0.0;
    value = 0.0;

    HiddenNeuron ** prevLayerArray = prevlayer->getNeurons();

    for (int i = 0; i < prevlayer->getNumNeurons(); i++)
        product = product + (prevLayerArray[i]->value * weights[i]);

    value = product;

    // prevLayerArray = NULL;
}

void HiddenNeuron::forward(InputLayer* inputlayer)
{
    double product = 0.0;
    value = 0.0;

    double* inputLayerArray = inputlayer->getInputs();

    for (int i = 0; i < inputlayer->getNumInputs(); i++)
        product = product + (inputLayerArray[i] * weights[i]);

    value = product;

    // inputLayerArray = NULL;
}

void HiddenNeuron::activateReLU()
{
    if (0 > value)
        value = 0;
}

void HiddenNeuron::activateSigmoid()
{
    double e = exp(1);
    double negativeValue = -1 * value;
    double result = 0;

    result = 1 / (1 + pow(e, negativeValue));
    value = result;
}