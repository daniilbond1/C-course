﻿#include <iostream>
using namespace std;

int govnina(const char* text, const char* pattern){

	int answer = -1;
	int i = 0;
	int z = 0;
	int k = 0;
	int sizeT = 0;
    int sizeP = 0;

	if (pattern[0] == '\0') {
		answer = 0;
		return answer;
	}

	while(pattern[sizeP] != '\0') {
		sizeP++;
	}

	while (text[sizeT] != '\0') {

		if (pattern[i] != text[z]) {
			sizeT++;
			z++;
		}

		if (pattern[i] == text[z]) {
			while (pattern[i] == text[z]){
					k++;
					i++;
					z++;
					if (k == sizeP) {
						answer = z - k;
						return answer;
					}
				}
			k = 0;
			i = 0;
			sizeT++;
            }
			
		}
	return answer;
	}



int main() {

	const char text[] = "jopa_ochko_perdun_kakulia_hhhhhhhhaha";

	const char pattern[] = "ochko";

	int answer = 0;

	answer = govnina(text, pattern);

	cout << answer;

	return 0;
}
