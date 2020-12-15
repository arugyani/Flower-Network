#include "train.h"
#include "../functions/functions.h"

using namespace std;

void Train::train_weights(int iterations, double learningRate, vector<vector<double>> data, vector<double> &w) {
    Functions f; f.populate(w);
    
    for (int i = 0; i < iterations; i++) {
        int random_index = static_cast<int> (rand() % data.size());
        vector<double> point = data.at(random_index);

        double z = point.at(0) * w.at(0) + point.at(1) * w.at(1) + point.at(2) * w.at(2) + point.at(3) * w.at(3) + w.at(4);
    
        double prediction = f.sigmoid(z);

        double target = point.at(4);
        double cost = f.square(prediction - target);

        double dcost_dpred = 2 * (prediction - target);
        double dpred_dz = f.sigmoid_derivative(z);
        double dz_dw1 = point.at(0);
        double dz_dw2 = point.at(1);
        double dz_dw3 = point.at(2);
        double dz_dw4 = point.at(3);
        double dz_db = 1;

        double dcost_dz = dcost_dpred * dpred_dz; 

        double dcost_dw1 = dcost_dz * dz_dw1;
        double dcost_dw2 = dcost_dz * dz_dw2;
        double dcost_dw3 = dcost_dz * dz_dw3;
        double dcost_dw4 = dcost_dz * dz_dw4;
        double dcost_db = dcost_dz * dz_db;

        w.at(0) = w.at(0) - learningRate * dcost_dw1;
        w.at(1) = w.at(1) - learningRate * dcost_dw2;
        w.at(2) = w.at(2) - learningRate * dcost_dw3;
        w.at(3) = w.at(3) - learningRate * dcost_dw4;

        w.at(4) = w.at(4) - learningRate * dcost_db;

        //cout << "Iteration " << i << "\n\tW1: " << w.at(0) << ", W2: " << w.at(1) << ", W3: " << w.at(2) << ", W4: " << w.at(3) << "\n\tBias: " << w.at(4) << ", Cost: " << cost << "\n\tPrediction: " << prediction << ", Target: " << target << endl;
    }

    saveWeights(w);
}

void Train::calculate(double sl, double sw, double pl, double pw, vector<double> weights) {
    Functions f;

    double z = sl * weights.at(0) + sw * weights.at(1) + pl * weights.at(2) + pw * weights.at(3) + weights.at(4);
    double prediction = (round(f.sigmoid(z) * 2) / 2.0);

    if (prediction == 0.0) cout << "Iris-Setosa" << endl;
    else if (prediction == 0.5) cout << "Iris-Versicolor" << endl;
    else if (prediction == 1) cout << "Iris-Virginica" << endl;
}

void Train::saveWeights(vector<double> weights) {
    ofstream saveFile;
    saveFile.open("./res/weights.txt");

    saveFile << weights.at(0) << "," << weights.at(1) << "," << weights.at(2) << "," << weights.at(3) << "," << weights.at(4);
}

void Train::loadWeights(vector<double> &weights) {
    ifstream inputFile;
    
    inputFile.open("./res/weights.txt");
    weights.clear();

    if (inputFile) {
        string str;
        double w1, w2, w3, w4, bias;

        if (!getline(inputFile, str)) {
            cout << "Error opening file \"weights.txt\"" << endl;
            exit(EXIT_FAILURE);
        }

        istringstream ss(str);
        vector<string> record;

         while (ss) {
                string s;
                if (!getline(ss, s, ',')) break;
                record.push_back(s);
        }

        w1 = stod(record[0]);
        w2 = stod(record[1]);
        w3 = stod(record[2]);
        w4 = stod(record[3]);
        bias = stod(record[4]);

        weights.push_back(w1);
        weights.push_back(w2);
        weights.push_back(w3);
        weights.push_back(w4);

        inputFile.close();
    } else {
        cout << "Error. File \"weights.txt\" wasn't found." << endl;
        exit(EXIT_FAILURE);
    }
}