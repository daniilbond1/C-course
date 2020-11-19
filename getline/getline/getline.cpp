
#include <iostream>
using namespace std;

char* resize(const char* str, unsigned size, unsigned new_size)
{
	char* p = new char[new_size];

	for (int i = 0; i <= new_size; i++) {
		p[i] = str[i];
	}
	delete[] str;	

	return p;
}

char* getline(){
	int new_size = 100;
	int size = 100;
	char* z = new char[size];
	int i = 0;
	char k;
	while (cin.get(k) && k != '\n') {
		if (i == size) {
			new_size = size+10;
			z = resize(z, size, new_size);
			size = new_size;
		}
		*z=k;
		z++;
		i++;
		
	}
	z[i]= '\0';

	for (int m = 0; m <= size; m++)
	{
		cout << z[m];
	}
	return z;
}



int main()
{
	getline();

	return 0;
}

