#include <vector>
#include <iostream>
using namespace std;

void kek(vector<vector<int>> first_type,vector<vector<int>>second_type) {

	int N = 0;
	int X = 0;
	int Y = 0;
	int type = 0;
	int max_x_1 = 0;
	int max_y_1 = 0;
	int max_x_2 = 0;
	int max_y_2 = 0;
	int max_x = 0;
	int max_y = 0;
	int counter_2 = 0;
	int counter_1 = 0;
	int counter_1_max = 0;
	int min_a = 100001;
	int min_b = 100001;

//	cin >> N;
//	vector<vector<int>> first_type;
//	vector<vector<int>> second_type;
//	for (int i = 0;i < N;i++) {
//		cin >> X >> Y >> type;
//		if (type == 2) { second_type.push_back({ X, Y }); }
//		if (type == 1) { first_type.push_back({ X, Y }); }
//	}


	//подсчитываю максимумы по икс и игрик для ВТОРОГО класса 
	for (int i = 0;i < second_type.size();i++) {
		if (max_x_2 < second_type[i][0]) {
			max_x_2 = second_type[i][0];
		}
	}

	for (int i = 0;i < second_type.size();i++) {
		if (max_y_2 < second_type[i][1]) {
			max_y_2 = second_type[i][1];
		}
	}

	//подсчитываю максимумы по икс и игрик для первого класса 
	for (int i = 0;i < first_type.size();i++) {
		if (max_x_1 < first_type[i][0]) {
			max_x_1 = first_type[i][0];
		}
	}

	for (int i = 0;i < first_type.size();i++) {
		if (max_y_1 < first_type[i][1]) {
			max_y_1 = first_type[i][1];
		}
	}
	//нахожу максимальный x и y
	if (max_x_1 > max_x_2) { max_x = max_x_1; }
	else { max_x = max_x_2; }

	if (max_y_1 > max_y_2) { max_y = max_y_1; }
	else { max_y = max_y_2; }





	//ищу возможные а и б, которые удволетворяют первому условию
	vector<vector<int>> first_condition;

	for (int x = max_x; x != 0; x--) {
		for (int y = max_y; y != 0; y--) {

			for (int i = 0;i < second_type.size();i++) {
				if (second_type[i][0] <= x) {
					if (second_type[i][1] <= y) {
						counter_2++;
					}
				}
			}

			if (counter_2 <= 5) {
				first_condition.push_back({ x, y });
			}
			counter_2 = 0;


		}
	}


	// ищу при каких а и б, удволетворяющих первому условию будет больше всего точек первого типа
	vector<vector<int>> second_condition;

	for (int i = 0;i < first_condition.size();i++) {
		for (int j = 0;j < first_type.size();j++) {


			if (first_type[j][0] <= first_condition[i][0]) {
				if (first_type[j][1] <= first_condition[i][1]) {
					counter_1++;
				}
			}

			if (counter_1 > counter_1_max) {
				counter_1_max = counter_1;
			}

			counter_1 = 0;

		}
	}


	for (int i = 0;i < first_condition.size();i++) {
		for (int j = 0;j < first_type.size();j++) {



			if (first_type[j][0] <= first_condition[i][0]) {
				if (first_type[j][1] <= first_condition[i][1]) {
					counter_1++;
				}
			}

			if (counter_1 == counter_1_max) {
				second_condition.push_back({ first_condition[i][0], first_condition[i][1] });
			}

			counter_1 = 0;

		}
	}


	// найдем способ с минимальным а 
	vector<vector<int>> minimum_a;
	for (int i = 0;i < second_condition.size();i++) {

		if (min_a > second_condition[i][0]) {
			min_a = second_condition[i][0];
		}
	}

	for (int i = 0;i < second_condition.size();i++) {
		if (min_a == second_condition[i][0]) {
			minimum_a.push_back({ second_condition[i][0], second_condition[i][1] });
		}
	
	}


	// найдем способ с минимальным б
	for (int i = 0;i < minimum_a.size();i++) {

		if (min_b > minimum_a[i][1]) {
			min_b = minimum_a[i][1];
		}
	}

	cout << min_a<<' ' << min_b;
}

int main()
{

	vector<vector<int>>first_type{ { 1,2 }, { 7,7 } };
	vector<vector<int>>second_type{ { 1,1 }, { 2,2 }, { 3,3 }, { 4,4 }, { 5,5 }, { 6,6 } };

	kek(first_type, second_type);
	
}
		
		




