#include <vector>
#include <iostream>
using namespace std;

void kek(vector<vector<int>> input) {

    int N = 0;
    int X = 0;
    int Y = 0;
    int TYPE = 0;
    int counter_2 = 0;
    int counter_1 = 0;
    int x = 0;
    int y = 0;
    int counter_1_max = 0;
    int min_a = 100001;
    int min_b = 100001;




    //cin >> N;
    //vector<vector<int>> input;
    //for (int i = 0;i < N;i++) {
    //  cin >> X >> Y >> type;
    //  input.push_back({ X, Y, type });
    //}

    //добавляю два стоблика, с количеством вторых и первых точек левее и ниже данной
    for (int k = 0; k < input.size(); k = k + 1) {
        x = input[k][0];
        y = input[k][1];

        for (int m = 0; m < input.size(); m = m + 1) {
            if ((input[m][0] <= x) && (input[m][1] <= y)) {

                if (input[m][2] == 2) {
                    counter_2++;
                }

                if (input[m][2] == 1) {
                    counter_1++;
                }

            }
        }
        input[k].push_back(counter_2);
        input[k].push_back(counter_1);
        counter_2 = 0;
        counter_1 = 0;
    }

    // удаляю все строчки где графа 3, больше 5
    for (int k = 0; k < input.size(); k = k + 1) {
        if (input[k][3] > 5) {
            if (input.size() > k)
            {
                input.erase(input.begin() + k);
            }
        }

    }

    // находим максимальное количество первых точек внутри данных
    for (int k = 0; k < input.size(); k = k + 1) {
        if (input[k][4] > counter_1_max) {
            counter_1_max = input[k][4];
        }
    }

    //удаляю все точки, которые меньше максимального значения по графе 4
    for (int k = 0; k < input.size(); k = k + 1) {
        if (input[k][4] != counter_1_max) {
            if (input.size() > k)
            {
                input.erase(input.begin() + k);
                k--;
            }
        }


    }

    // находим минимальное значение Х среди данных
    for (int k = 0; k < input.size(); k = k + 1) {
        if (input[k][0] < min_a) {
            min_a = input[k][0];
        }
    }

    // удаляем все строчки со значением X, которые не равны минимуму
    for (int k = 0; k < input.size(); k = k + 1) {
        if (input[k][0] != min_a) {

            if (input.size() > k)
            {
                input.erase(input.begin() + k);
                k--;
            }
        }

    }

    // находим минимальное значение Y среди данных
    for (int k = 0; k < input.size(); k = k + 1) {
        if (input[k][1] < min_b) {
            min_b = input[k][1];
        }
    }

    cout << min_a << " " << min_b;

}




int main()
{

   //vector<vector<int>>first_type{ { 1,2,1 }, { 7,7,1 },{ 1,1,2 }, { 2,2,2 }, { 3,3,2 }, { 4,4,2 }, { 5,5,2 }, { 6,6,2 } };
    //vector<vector<int>>first_type{ { 1,2,2 }, { 1,3,2 },{ 1,1,2 }, { 1,4,2 }, { 1,5,2 }, { 1,6,2 }, { 2,2,1 }, { 2,1,1 } };
    //vector<vector<int>>first_type{ { 2,2,1 }, { 8,8,1 },{ 5,5,2 }, { 1,8,2 }, { 5,8,2 }, { 8,4,2 }, { 8,2,2 } };
    //vector<vector<int>>first_type{ { 2,2,1 }, { 8,8,1 },{ 5,5,2 }, { 1,8,2 }, { 5,8,2 }, { 8,4,2 }, { 8,2,2 } };
    //vector<vector<int>>first_type{ { 2,2,1 }, { 8,8,1 },{ 1000,1000,1 }};
    //vector<vector<int>>first_type{ { 2,2,1 }, { 4,4,1 },{ 5,5,1 }, { 1,8,2 }, { 5,8,2 }, { 8,4,2 }, { 8,2,2 } };
     vector<vector<int>>first_type{ { 1,1,1 }, { 2,2,1 },{ 3,3,1 }, { 4,4,1 }, { 5,5,1 }, { 6,6,1 }, { 7,7,1 } };
     kek(first_type);
   
}