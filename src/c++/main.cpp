#include "functions/functions.h"
#include "data/data.h"
#include "training/train.h"
#include <iostream>


using namespace std;

// Instances
Functions f;
Data d;
Train t;

//Variables
vector<vector<double>> trainingData = d.loadFile("./res/Iris/iris.data"); // Loads data into vector
vector<double> weights;

int main() {
    //t.train_weights(10000, 0.05, trainingData, weights);
    //t.loadWeights(weights);
    //t.calculate(6.9, 3.2, 5.8, 2, weights);

    return 0;
}