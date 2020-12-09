
#include <iostream>
using namespace std;
#include <vector>


int dec2bin(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}

bool valid(int sizitens_num, vector<int> statements) {
    return true;
}


int knights_num(int sizitens_num, vector<int> statements) {

    int lier = 0;
    int knight=0;
    vector<int> knight_pos;
    vector<int>  lier_pos;

    

    for (int i = 0; i < pow(2, sizitens_num); i++) {

        int bin_number = dec2bin(i);

        vector<int> predictions;

        predictions.push_back(0);


        while (bin_number > 0)
        {
            predictions.push_back(bin_number % 10);
            bin_number /= 10;
        }

        reverse(predictions.begin(), predictions.end());

        for (std::vector<int>::const_iterator k = predictions.begin(); k != predictions.end(); ++k)
            std::cout << *k << ' ';

        cout << "\n";
        
    }



    return -1;
}


int main()
{
    int sizitens_num;
    vector<int> statements;
   

    cin >> sizitens_num;

    for (int i = 0; i < sizitens_num; ++i) {
        int statement;
        cin >> statement;
        statements.push_back(statement);
    }

    cout << knights_num(sizitens_num, statements);

    return 0;
}


