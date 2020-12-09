#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> binary (int n, int size) {
    vector<int> binary;

    for (int i = size - 1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            binary.push_back(1);
        else
            binary.push_back(0);
    }

    return binary;
}

bool check(vector<int> predictions, vector<int> statements) {
    int sizitens_num = predictions.size();
    int knights_num = count(predictions.begin(), predictions.end(), 1);


    for (int i = 0; i < sizitens_num; ++i) {
        int person = predictions[i];
        int statement = statements[i];

        if (person == 1) {
            if (knights_num > statement) {
                return false;
            }
        }
        else {
            if (knights_num <= statement) {
                return false;
            }
        }
    }

    return true;
}

vector<vector<int>> generate_predictions(int sizitens_num) {
    vector<vector<int>> predictions;

    for (int i = 0; i < pow(2, sizitens_num); i++) {
        vector<int> prediction = binary(i, sizitens_num);

        predictions.push_back(prediction);
    }

    return predictions;
}



int knights(vector<int> statements) {

    bool utterance = true;

    int sizitens = statements.size();

    vector<vector<int>> predictions = generate_predictions(sizitens);

    for (vector<vector<int>>::const_iterator prediction = predictions.begin();
        prediction != predictions.end(); ++prediction) {
        utterance = check(*prediction, statements);
        if (utterance) {
            int knights_num = count(prediction->begin(), prediction->end(), 1);
            return knights_num;

        }

    }

    return -1;
}



int main() {
    int sizitens;
    vector<int> statements;

    cin >> sizitens;

    for (int i = 0; i < sizitens; ++i) {
        int statement;
        cin >> statement;
        statements.push_back(statement);
    }

    int result = knights(statements);

    cout << result;


}