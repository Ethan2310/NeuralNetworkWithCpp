#ifndef INPUTLAYER_H
#define INPUTLAYER_H

class InputLayer
{
    private:
        int numInputs;
        double * inputs;
        
    public:
        InputLayer(int);
        ~InputLayer();
        double * getInputs();
        int getNumInputs();
        void setInputs(double *);
        void setNumInputs(int);
        void printLayer();
        void clearLayer();
};

#endif