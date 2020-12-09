#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> create_submatrix(vector<vector<int>> matrix, int size_x, int size_y, int max_y) {

	vector<vector<int> >submatrix;

	for (int i = 0; i < size_x; i++) {
		vector<int> row;
		for (int j = 0; j < size_y; j++) {
			row.push_back(matrix[max_y-i-1][j]);
		}
		submatrix.insert(submatrix.begin(), row);
	}

	return submatrix;
}




void iterate_submatrix(vector<vector<int>> matrix, int max_x, int max_y) {

	int counter_1 = 0;
	int counter_2 = 0;
	int max_1 = 1;
	int a = 0;
	int b = 0;

	for (int i = 1; i <= max_x; i++) {
		for (int j = 1; j <= max_y; j++) {
			vector<vector<int> >submatrix = create_submatrix(matrix, j, i, max_y);

			for (int k = 0; k < submatrix.size(); k = k + 1) {
				for (int l = 0; l < submatrix[k].size(); l = l + 1) {
					if (submatrix[k][l] == 2) {
						counter_2++;
					}

					if (submatrix[k][l] == 1) {
						counter_1++;
					}


				}
			}

			if (counter_2 <= 5) {
				if (counter_1 >= max_1) {
					max_1 = counter_1;
					if (i <= a) {
						a = i;
					}
					if (j <= b) {
                     b = j;
					}
					
				}

			}
		}
	
	}
	cout << a << b;
}



int main()
{
	int N = 0;
	int x = 0;
	int y = 0;
	int type = 0;
	int max_x = 0;
	int max_y = 0;
	int conteiner_x = 0;
	int conteiner_y = 0;

	cin >> N;
	vector<vector<int>> input;
	for (int i = 0;i < N;i++) {
		cin >> x >> y >> type;
		input.push_back({ x, y, type });
	}

	for (int i = 0;i < N;i++) {
		if (max_x < input[i][0]) {
			max_x = input[i][0];
		}
	}

	for (int i = 0;i < N;i++) {
		if (max_y < input[i][1]) {
			max_y = input[i][1];
		}
	}

	vector<vector<int> > matrix(max_y);
	for (int i = 0; i < max_y; i++) {
		matrix[i].resize(max_x);
	}	
	

	for (int i = 0;i < N;i++) {
		conteiner_x = input[i][0];
		conteiner_y = input[i][1];
		matrix[max_y-conteiner_y][conteiner_x-1] = input[i][2];
	}


	iterate_submatrix(matrix,max_x,max_y);

	return 0;

}
