#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

using namespace std;

class Data {
    public:
        vector<vector<double>> loadFile(string arr);
        void print(vector<vector<double>> data);

};

#endif