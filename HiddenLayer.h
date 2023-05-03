#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H
#include <string>
#include "HiddenLayer.h"
#include "InputLayer.h"

#include "HiddenNeuron.h"

class HiddenLayer
{
    private:
        int numNeurons;
        HiddenNeuron** neurons;
        std::string activation;

    public:
        HiddenLayer(int, HiddenNeuron**, std::string);
        ~HiddenLayer();
        HiddenNeuron ** getNeurons();
        void setNeurons(HiddenNeuron**);
        int getNumNeurons();
        void setNumNeurons(int);
        void forward(HiddenLayer*);
        void forward(InputLayer*);
        void printLayer();
        void clearLayer();
};

#endif