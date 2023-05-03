#include "NeuralNetwork.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

NeuralNetwork::NeuralNetwork(string filePath)
{
    int numInputNeurons, numHiddenNeurons, prevLayerSize, numOutputNeurons;
    string numInputs, numLayers, activationCode, numOutput;

    ifstream inputFile;
    string line;
    inputFile.open(filePath.c_str());
    
    if (inputFile)
    {
        //=============== Get Number of neurons in InputNeuron BEGIN ===============
        getline(inputFile, line);
        istringstream inputNeurons(line);
        getline(inputNeurons, numInputs, ':');
        getline(inputNeurons, numInputs, ':');
        stringstream convertToIntx(numInputs);
        convertToIntx >> numInputNeurons;
        // cout << "i: " << numInputNeurons << endl;

        inputLayer = new InputLayer(numInputNeurons);
        //=============== Get Number of neurons in InputNeuron END ===============


        //=============== Get Number of HiddenLayers BEGIN ===============
        getline(inputFile, line);
        istringstream hiddenLayerNeurons(line);
        getline(hiddenLayerNeurons, numLayers, ':');
        getline(hiddenLayerNeurons, numLayers, ':');
        stringstream convertToIntxx(numLayers);
        convertToIntxx >> numHiddenLayers;

        // cout << "num_hidden_layers: " << numHiddenLayers << endl;
        //=============== Get Number of HiddenLayers END ===============


        //=============== Get Weights of Neurons in each HiddenLayer BEGIN ===============
        hiddenLayers = new HiddenLayer*[numHiddenLayers];
        prevLayerSize = numInputNeurons;

        for (int l = 0; l < numHiddenLayers; l++)
        {
            // ************** Read basic information about a Hidden Layer BEGIN **************
            getline(inputFile, line);
            // cout << "Line: " << line << endl;
            string substring;
            istringstream basicInfo(line);

            getline(basicInfo, substring, ':');
            getline(basicInfo, substring, ':');
            stringstream convertToInt3(substring);
            convertToInt3 >> numHiddenNeurons;

            // cout << "h: " << numHiddenNeurons << endl;

            if (getline(basicInfo, substring, ':'))
            {
                activationCode = substring;
                // cout << "code: " << activationCode << endl;
            }
            else 
            {
                activationCode = "";
                // cout << "no activation code\n";
            }
            // ************** Read basic information about a Hidden Layer END **************
            

            // ************** Read the weights for the HiddenNeurons in a HiddenLayer BEGIN **************
            HiddenNeuron ** arrHiddenNeurons = new HiddenNeuron*[numHiddenNeurons];
            
            for (int h = 0; h < numHiddenNeurons; h++)
            {
                getline(inputFile, line);
                string substring2;
                istringstream weightInfo(line);

                double * weightsArray = new double[prevLayerSize];
                int index = 0;

                while (getline(weightInfo, substring2, ' '))
                {
                    double temp;
                    stringstream convertToDouble(substring2);
                    convertToDouble >> temp;
                    weightsArray[index] = temp;
                    // cout << weightsArray[index] << " ";
                    index++;
                }
                // cout << "\n";

                arrHiddenNeurons[h] = new HiddenNeuron(index, weightsArray);
            }

            // cout << "numHiddenNeurons: " << numHiddenNeurons << endl;
            hiddenLayers[l] = new HiddenLayer(numHiddenNeurons, arrHiddenNeurons, activationCode);
            prevLayerSize = numHiddenNeurons;
            // ************** Read the weights for the HiddenNeurons in a HiddenLayer END **************
        }
        //=============== Get Weights of Neurons in each HiddenLayer END ===============


        //=============== Finish up the Output BEGIN ===============
        getline(inputFile, line);
        numOutputNeurons = 1;
        // cout << "o: " << numOutputNeurons << endl;
        // cout << prevLayerSize << endl;

        getline(inputFile, line);
        string substring3;
        istringstream outputInfo(line);

        double* outputArray = new double[prevLayerSize];
        int outputIndex = 0;

        while (getline(outputInfo, substring3, ' '))
        {
            double temp2;
            stringstream convertToDouble2(substring3);
            convertToDouble2 >> temp2;
            outputArray[outputIndex] = temp2;
            // cout << outputArray[outputIndex] << " ";
            outputIndex++;
        }
        // cout << "\n";
        
        outputLayer = NULL;
        outputLayer = new OutputLayer(numOutputNeurons, outputArray);
        // cout << "I'm here!\n";
        //=============== Finish up the Output END ===============



        // //@@@@@@@@@@@@@@@@@@@@@@@@@@@ DEBUG BEGIN @@@@@@@@@@@@@@@@@@@@@@@@@@@

        // double *inputarr = inputLayer->getInputs();    



        // //@@@@@@@@@@@@@@@@@@@@@@@@@@@ DEBUG END @@@@@@@@@@@@@@@@@@@@@@@@@@@
      
    }
    else
    cout << "Error opening the text file.\n";

    inputFile.close();
}

NeuralNetwork::~NeuralNetwork()
{
    delete inputLayer;

    for (int hl = 0; hl < numHiddenLayers; hl++)
        delete hiddenLayers[hl];
    delete [] hiddenLayers;

    delete outputLayer;
}

double NeuralNetwork::forward(double* input)
{
    inputLayer->setInputs(input);

    hiddenLayers[0]->forward(inputLayer);

    for (int hl = 1; hl < numHiddenLayers; hl++)
        hiddenLayers[hl]->forward(hiddenLayers[hl - 1]);

    outputLayer->forward(hiddenLayers[numHiddenLayers - 1]);

    return outputLayer->getOutputValue();
}

void NeuralNetwork::printNetwork()
{
    inputLayer->printLayer();
    
    for (int hl = 0; hl < numHiddenLayers; hl++)
        hiddenLayers[hl]->printLayer();

    outputLayer->printLayer();
}

void NeuralNetwork::clearNetwork()
{
    inputLayer->clearLayer();

    for (int hl = 0; hl < numHiddenLayers; hl++)
        hiddenLayers[hl]->clearLayer();

    outputLayer->clearLayer();
}