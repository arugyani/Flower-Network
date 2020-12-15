#include "functions.h"
#include <cmath>
#include <algorithm>
#include <random>
#include <time.h>
#include <vector>

// Activation Functions
double Functions::sigmoid(double x) {
    return (1 / (1 + exp(-x)));
}

// Derivatives
double Functions::sigmoid_derivative(double x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

// Square Values
double Functions::square(double a) {
    return a * a;
}

void Functions::populate(std::vector<double> &arr) {
    std::srand((unsigned) time( NULL ));

    for (int i = 0; i < 5; i++) {
        arr.push_back((float) rand() / RAND_MAX);
    }
}

// Shuffle
std::vector<std::vector<double>> Functions::shuffle(std::vector<std::vector<double>> arr) {
    auto rnd = std::default_random_engine {};
   
    std::shuffle(std::begin(arr), std::end(arr), rnd);

    return arr;
}

