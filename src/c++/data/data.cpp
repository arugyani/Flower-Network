#include "data.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void Data::print(vector<vector<double>> data) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.at(i).size(); j++) {
            if (j == 0) cout << data.at(i).at(j);
            else cout << ", " << data.at(i).at(j);
        }

        cout << endl;
    }    
}


vector<vector<double>> Data::loadFile(string url) {
    vector<vector<double>> arr;
    vector<vector<string>> data;

    ifstream inputFile;
    inputFile.open(url);

    if (inputFile) {
        while(inputFile) {
            string str;
            if(!getline(inputFile, str)) break;

            istringstream ss(str);
            vector<string> record;

            while (ss) {
                string s;
                if (!getline(ss, s, ',')) break;
                record.push_back(s);
            }

            data.push_back(record);
        }

        inputFile.close();
    } else {
        cout << "Error. File \"" << url << "\" could not be opened." << endl;
    }

    for (int i = 0; i < data.size(); i++) {
        vector<double> tempArr;

        double sepalLength = stod(data.at(i).at(0));
        double sepalWidth = stod(data.at(i).at(1));
        double petalLength = stod(data.at(i).at(2));
        double petalWidth = stod(data.at(i).at(3));

        double classification = (data.at(i).at(4) == "Iris-setosa") ? (0.0) : ((data.at(i).at(4) == "Iris-versicolor") ? 0.5 : 1.0);
   
        tempArr.push_back(sepalLength);
        tempArr.push_back(sepalWidth);
        tempArr.push_back(petalLength);
        tempArr.push_back(petalWidth);
        tempArr.push_back(classification);

        arr.push_back(tempArr);
    }
    
    return arr;
}