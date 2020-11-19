#include <iostream>
using namespace std;
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy 

struct String {

    /* Реализуйте этот конструктор */
    String(size_t n, char c)
    {
       str = new char[size + 1];
        for (int i = 0;i <= size; i++) {
            str[i] = c;
        }
    }
    /* и деструктор */
    ~String()
    {
        delete str;
    }

    size_t size;
    char* str;
};

void main() {

	const char* s = "jipjep";

	String p(s);
}