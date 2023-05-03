#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "InputLayer.h"
#include "HiddenNeuron.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include "NeuralNetwork.h"

using namespace std;

int main()
{
    double* inputArray = new double[1];
    NeuralNetwork test("sin(x).txt");
    test.printNetwork();
    cout << setprecision(15);
    cout << "===============================\n";

    //input #1
    inputArray[0] = 0.0;
    cout << inputArray[0] << endl;
    cout << test.forward(inputArray) << endl;
    cout << "===============================\n";

    double* anotherArray2 = new double[1];
    //input #2
    anotherArray2[0] = 1.0;
    cout << anotherArray2[0] << endl;
    cout << test.forward(anotherArray2) << endl;
    cout << "===============================\n";


    double* anotherArray = new double[1];
    //input #3
    anotherArray[0] = -1.0;
    cout << anotherArray[0] << endl;
    cout << test.forward(anotherArray) << endl;
    cout << "===============================\n";

    //input #4
    double* anotherArray3 = new double[1];
    anotherArray3[0] = 5.0;
    cout << anotherArray3[0] << endl;
    cout << test.forward(anotherArray3) << endl;
    cout << "===============================\n";

    //input #5
    double* anotherArray34 = new double[1];
    anotherArray34[0] = 1.5;
    cout << anotherArray34[0] << endl;
    cout << test.forward(anotherArray34) << endl;
    cout << "===============================\n";

    
    // cout << "===============================\n";
    // test.clearNetwork();
    // cout << inputArray[0] << endl;
    // test.printNetwork();

    return 0;
}