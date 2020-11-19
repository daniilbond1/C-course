#include <iostream>
using namespace std;

void govnina(char* to, const char* from)
{
		while (*to != '\0') {
			to++;
		}
		while (*from != '\0') {
			*to = *from;
			from++;
			to++;
		}
		to++;
		*to = '\0';
		return;
	}

void main() {
	char to[7] = "";
	char from[3] = "rt";
		govnina(to, from);
		cout << to;

}