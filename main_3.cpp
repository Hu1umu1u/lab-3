#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

int main() {
    system("chcp 65001>nul");
    int choice;
    std::cout << "Выберите:\n1. Работа с массивом (38 элементов)\n2. Работа с матрицей (9x11)\n";
    std::cin >> choice;

#ifdef _WIN32
    HINSTANCE hLib;
    if (choice == 1) {
        hLib = LoadLibrary("array_lib.dll");
    } else {
        hLib = LoadLibrary("matrix_lib.dll");
    }
#else
    void* hLib;
    if (choice == 1) {
        hLib = dlopen("./array_lib.so", RTLD_LAZY);
    } else {
        hLib = dlopen("./matrix_lib.so", RTLD_LAZY);
    }
#endif

    if (!hLib) {
        std::cerr << "Ошибка загрузки библиотеки!" << std::endl;
        return 1;
    }

    if (choice == 1) {
        int array[38];

#ifdef _WIN32
        void (*fill_array)(int*, int) = (void (*)(int*, int)) GetProcAddress(hLib, "fill_array");
        int (*count_mod5_equals_1_array)(int*, int) = (int (*)(int*, int)) GetProcAddress(hLib, "count_mod5_equals_1_array");
#else
        void (*fill_array)(int*, int) = (void (*)(int*, int)) dlsym(hLib, "fill_array");
        int (*count_mod5_equals_1_array)(int*, int) = (int (*)(int*, int)) dlsym(hLib, "count_mod5_equals_1_array");
#endif

        fill_array(array, 38);
        int count = count_mod5_equals_1_array(array, 38);
        std::cout << "Число элементов массива, остаток от деления на 5 которых равен 1: " << count << std::endl;

    } else if (choice == 2) {
        int matrix[9][11];

#ifdef _WIN32
        void (*fill_matrix)(int[9][11]) = (void (*)(int[9][11])) GetProcAddress(hLib, "fill_matrix");
        int (*count_mod5_equals_1_matrix)(int[9][11]) = (int (*)(int[9][11])) GetProcAddress(hLib, "count_mod5_equals_1_matrix");
#else
        void (*fill_matrix)(int[9][11]) = (void (*)(int[9][11])) dlsym(hLib, "fill_matrix");
        int (*count_mod5_equals_1_matrix)(int[9][11]) = (int (*)(int[9][11])) dlsym(hLib, "count_mod5_equals_1_matrix");
#endif

        fill_matrix(matrix);
        int count = count_mod5_equals_1_matrix(matrix);
        std::cout << "Число элементов матрицы, остаток от деления на 5 которых равен 1: " << count << std::endl;
    }

#ifdef _WIN32
    FreeLibrary(hLib);
#else
    dlclose(hLib);
#endif
    std::cout << "Нажимите Enter для завершения работы программы...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}
