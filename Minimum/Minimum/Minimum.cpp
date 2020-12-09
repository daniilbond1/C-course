#include <iostream>
#include <cstddef>
#include <array>
using namespace std;


bool less1(int a, int b) { return a < b; }
struct Greater { bool operator()(int a, int b) const { return b < a; } };

template <typename type_array, typename type_function>
type_array  minimum(array <type_array,3> Array, type_function function) {
	type_array a = Array[0];
	type_array min = Array[0];
	for (int i = 1;i < Array.size();i++) {
		a = function(min, Array[i]);
		if (a != 1) {
			min = Array[i];
		}
	}

	return min;
}


int main() {
	array<int,3> ints;
	ints[0] = 10;
	ints[1] = 2;
	ints[2] = 15;
	int min = minimum(ints, less1); // в min должно попасть число 2
	int max = minimum(ints, Greater()); // в max должно попасть число 15
    
	cout << "min:"<<min<<endl;
	cout << "max:" << max<<endl;

	return 0;
}

