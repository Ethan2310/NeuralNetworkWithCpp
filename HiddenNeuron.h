#ifndef HIDDENNEURON_H
#define HIDDENNEURON_H
#include "InputLayer.h"

class HiddenLayer;

class HiddenNeuron
{
    private:
        double value;
        int numWeights;
        double * weights;  

    public:
        HiddenNeuron(int, double*); 
        ~HiddenNeuron();  
        double getValue();
        void setValue(double);
        void forward(HiddenLayer*);
        void forward(InputLayer*);
        void activateReLU();
        void activateSigmoid();
};

#endif