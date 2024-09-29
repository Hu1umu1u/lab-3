#include <cstdlib>
#include <ctime>

extern "C" int count_mod5_equals_1_array(int* array, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] % 5 == 1) {
            ++count;
        }
    }
    return count;
}

extern "C" void fill_array(int* array, int size) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 101 - 50;
    }
}
