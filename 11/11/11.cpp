#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> dict;

bool nakritie(string a) {

    int size = 0;
    int ostatok = 0;
    int seredina = 0;
    
 
    string b;
    string c;

    


    size = a.length();

    ostatok = size % 2;


    if (size == 1) {
        return false;
    }

    if (ostatok == 1) {
        seredina = (size - 1) / 2;
        for (int k = 0; k != seredina;k++) {
            
            c = a.substr(0, seredina + 1 + k);
            b = a.substr(seredina - k, size);

            bool comparation_result;

            auto it1 = dict.find(c + b);
            auto it2 = dict.find(b + c);

            if (it1 == dict.end()) {
                if (it2 == dict.end()) {
                    comparation_result = b.compare(c) == 0;
                    dict.insert({ c + b,comparation_result });
                }
                else {
                    comparation_result = it2->second;
                }
            }
            else {
                comparation_result = it1->second;
            }

            if (comparation_result == true) {

                return true;
            }
;
        }
        return  false;
    }

    if (ostatok == 0) {
        seredina = size / 2;
        for (int k = 0; k != seredina;k++) {

            c = a.substr(0, seredina + k);
            b = a.substr(seredina - k, size);
           
            bool comparation_result;

            auto it1 = dict.find(c + b);
            auto it2 = dict.find(b + c);

            if (it1 == dict.end()) {
                if (it2 == dict.end()) {
                    comparation_result = b.compare(c) == 0;
                    dict.insert({ c + b,comparation_result });
                }
                else {
                    comparation_result = it2->second;
                }  
            }
            else {
                comparation_result = it1->second;
            }

            if (comparation_result == true) {
             
                return true;
            }          
            
        }

        return  false;
    }

}


int main()
{
    int size = 0;
    int nashlo = 0;
    string a;
    string b;


    cin >> a;
    size = a.length();

    

    for (int i = 0;i != size;i++) {
        b = b + a[i];
        if (nakritie(b) == true) {

            nashlo++;
        }

    }

    cout << nashlo;


    return 0;
}