
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void flatten(T& value){

            cout << value << " ";
}

template <typename T>
void flatten( vector<T>& array)
{
    size_t size_a;
    size_a = array.size();

    for (int i = 0; i < size_a; i++) {
        flatten(array[i]);
    }

    return;
}


int main()
{
   
    vector<vector<int> > a(3, vector<int>(3, 1));
        
    flatten(a);

    return 0;
    
}

