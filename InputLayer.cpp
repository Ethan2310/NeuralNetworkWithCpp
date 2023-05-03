#include "InputLayer.h"
#include <iostream>
#include <cstdlib>
using namespace std;

InputLayer::InputLayer(int numinput)
{
    numInputs = numinput;
    inputs = NULL;
}

InputLayer::~InputLayer()
{
    if (inputs != NULL)
    {
        delete [] inputs;
        inputs = NULL;
    }
    
    // cout << "IL destroyed\n";
}

double * InputLayer::getInputs()
{
    return inputs;
}

int InputLayer::getNumInputs()
{
    return numInputs;
}

void InputLayer::setInputs(double * input)
{
    if (inputs == NULL)
        inputs = input;

    else if (inputs != NULL)
    {
        // delete [] inputs;
        inputs = NULL;
        inputs = input;
    }
}

void InputLayer::setNumInputs(int numinput)
{
    numInputs = numinput;
}

void InputLayer::printLayer()
{
    cout << "i:" << numInputs << endl;
}

void InputLayer::clearLayer()
{
    if (inputs != NULL)
    {
        for (int i = 0; i < numInputs; i++)
            inputs[i] = 0.0;
    }   
}