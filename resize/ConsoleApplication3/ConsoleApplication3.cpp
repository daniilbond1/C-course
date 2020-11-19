#include <iostream>
using namespace std;

char* resize(const char* str, unsigned size, unsigned new_size)
{
	 char* p = new char[new_size];

	 for (int i = 0; i++; i <= size) {
		 *p = *str;
		 p++;
		 str++;
	 }
	 delete[] str;

	return p;
}


int main() {
	unsigned size = 100;
	unsigned new_size = 200;
	const char* str ="zalupa228";
	
	
	resize(str, size, new_size);


	return 0;
}
