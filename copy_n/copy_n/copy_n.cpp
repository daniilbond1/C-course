
#include <iostream>
#include <conio.h>
using namespace std;

template < typename type_U, typename type_T >
void copy_n(type_T* T, type_U* U, int num) {

	for (int i = 0;i < num;i++) {
		*T = (type_T)*U;
		U++;
		T++;
	}

}
int main()
{
	int ints[] = { 1, 2, 3, 4 };
	double doubles[4] = {};
	copy_n(doubles, ints, 4);
	for (int t = 0; t != 4; t++)
		std::cout << doubles[t];
	return 0;
}