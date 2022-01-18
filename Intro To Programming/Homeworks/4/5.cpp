#include <iostream>
#include <vector>

using namespace std;

const int VECTOR_DIMENSIONS = 4;

int main() {
    int n,m;
    cin >> n >> m;
    //export to functions
    vector<vector<double>> uMatrix;
    for (int i = 0; i < n; ++i) {
        vector<double> vector = {};
        for (int j = 0; j < VECTOR_DIMENSIONS; ++j) {
            double num;
            cin >> num;
            vector.push_back(num);
        }
        uMatrix.push_back(vector);
    }
    vector<vector<double>> wMatrix;
    for (int i = 0; i < m; ++i) {
        vector<double> vector = {};
        for (int j = 0; j < VECTOR_DIMENSIONS; ++j) {
            double num;
            cin >> num;
            vector.push_back(num);
        }
        wMatrix.push_back(vector);
    }

    vector<vector<double>> finalMatrix;
    //Guassian to uMatrix
    for (int i = 0; i < m; ++i) {
        //permutation check if it works
        vector<double> line = wMatrix[i];
        int pivot = line[i];
        if (pivot == 0) {
            for (int j = n - 1; j >= 0; --j) {
                if (wMatrix[j][i] != 0) {
                    vector<double> tempLine = line;
                    line = wMatrix[j];
                    wMatrix[j] = tempLine;
                    break;
                }
            }
        }
        else {
            finalMatrix.push_back(line);
            for (int j = i + 1; j < m; ++j) {
                int numberUnderThePivot = wMatrix[j][i];
                // if it has numbers under the pivot
                if (numberUnderThePivot != 0) {
                    vector<double> lineToTransform = wMatrix[j];
                    double changer = ((double)numberUnderThePivot / pivot) * -1;

                    for (int k = 0; k < VECTOR_DIMENSIONS; ++k) {
                        //check if it yields the correct result
                        lineToTransform[k] = lineToTransform[k] + (changer * line[k]);
                    }

                    wMatrix[j] = lineToTransform;
                } 
            }
        }
    }

    //rref for uMatrix





    return 0;
}

