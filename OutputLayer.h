#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H
#include "HiddenLayer.h"
#include "HiddenNeuron.h"

class OutputLayer
{
    private:
        double outputValue;
        int numWeights;
        double * weights;
    
    public:
        OutputLayer(int, double *);
        ~OutputLayer();
        double getOutputValue();
        void setOutputValue(double);
        void forward(HiddenLayer*);
        void printLayer();
        void clearLayer();
};

#endif