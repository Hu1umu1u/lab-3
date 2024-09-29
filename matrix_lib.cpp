#include <cstdlib>
#include <ctime>

extern "C" int count_mod5_equals_1_matrix(int matrix[9][11]) {
    int count = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (matrix[i][j] % 5 == 1) {
                ++count;
            }
        }
    }
    return count;
}

extern "C" void fill_matrix(int matrix[9][11]) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 11; ++j) {
            matrix[i][j] = rand() % 101 - 50;
        }
    }
}
