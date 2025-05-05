#include <iostream>
using namespace std;

const int SIZE = 3;

bool LoShuMagicSq(int grid[SIZE][SIZE]) {
    bool seen[10] = {false};  

    int Magic_Sum = 15;

   
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j) {
            int N = grid[i][j];
            if (N < 1 || N > 9 || seen[N]) return false;
            seen[N] = true;
        }

  
    for (int i = 0; i < SIZE; ++i) {
        int Sum_Row = 0, Sum_Col = 0;
        for (int j = 0; j < SIZE; ++j) {
            Sum_Row += grid[i][j];
            Sum_Col += grid[j][i];
        }
        if (Sum_Row != Magic_Sum || Sum_Col != Magic_Sum) return false;
    }


    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < SIZE; ++i) {
        diag1 += grid[i][i];
        diag2 += grid[i][SIZE - i - 1];
    }

    return diag1 == Magic_Sum && diag2 == Magic_Sum;
}

int main() {
    int grid[SIZE][SIZE];

    cout << "Please enter the desire grid dimension: 3 3 " << endl;
    cout << "Output for 3 x 3 Grid: " << endl;
    cout << "\t" << endl;

   
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            cin >> grid[i][j];



    if (LoShuMagicSq(grid)) {
        cout << "This is a Lo Shu Magic Square." << endl;
        cout << "And, the magic number is 15." << endl;
    } else {
        cout << "This is not a Lo Shu Magic Square." << endl;
    }

    cout << "\t" << endl;
    cout << "Thank you!!!" << endl;

    return 0;
}
