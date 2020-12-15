#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
#include <iostream>
#include <random>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Train {
    public:
        void train_weights(int iterations, double learningRate, vector<vector<double>> data, vector<double> &w);
        void calculate(double sl, double sw, double pl, double pw, vector<double> weights);
        void saveWeights(vector<double> weights);
        void loadWeights(vector<double> &weights);
};

#endif