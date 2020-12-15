#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

class Functions {
     public:
        double sigmoid(double x);
        double sigmoid_derivative(double x);
        double square(double a);

        void populate(std::vector<double> &arr);
        
        std::vector<std::vector<double>> shuffle(std::vector<std::vector<double>> arr);
};

#endif