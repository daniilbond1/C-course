#include <iostream>
#include <vector>
using namespace std;


int main()
{
	double x1 = 0;
	int counter_x1_1 = 0;
	int  counter_x1_2 = 0;

	double x2 = 0;
	int counter_x2_1 = 0;
	int  counter_x2_2 = 0;

	double y1 = 0;
	int counter_y1_1 = 0;
	int  counter_y1_2 = 0;

	double y2 = 0;
	int counter_y2_1 = 0;
	int  counter_y2_2 = 0;

	vector<vector<double>> input;
	for (int i = 0;i < 1000;i++) {
		cin >> x1 >> x2 >> y1>> y2;
		input.push_back({ x1,x2,y1,y2 });
	}

	for (int i = 0;i < 1000;i++) {
		if (x1 < 0.5) { counter_x1_1++; }
		if (x1 > 0.5) { counter_x1_2++; }
	}
	counter_x1_2 = counter_x1_2 - 500;

	for (int i = 0;i < 1000;i++) {
		if (x2 < 0.5) { counter_x2_2++; }
		if (x2 > 0.5) { counter_x2_1++; }
	}
	counter_x2_2 = counter_x2_1 - 500;

	for (int i = 0;i < 1000;i++) {
		if (y1 < 0.5) { counter_y1_1++; }
		if (y1 > 0.5) { counter_y1_2++; }
	}
	counter_y1_2 = counter_y1_2 - 500;

	for (int i = 0;i < 1000;i++) {
		if (y2 < 0.5) { counter_y2_2++; }
		if (y2 > 0.5) { counter_y2_1++; }
	}
	counter_y2_1 = counter_y2_1 - 500;

	if ((counter_x1_1 > counter_x1_2) && (counter_x2_1 > counter_x2_2) && (counter_y1_1 > counter_y1_2) && (counter_y2_1 > counter_y2_2)) {
		cout << 1;
	}
	else { cout << 2; }

}
