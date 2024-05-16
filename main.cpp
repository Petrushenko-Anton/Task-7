/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
void fillArrayRandom(int** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % 100; // случайные числа от 0 до 99
        }
    }
}
void fillArrayInput(int** arr, int n, int m) {
    std::cout << "Введите " << n * m << " целых чисел для заполнения массива:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> arr[i][j];
        }
    }
}
void printArray(int** arr, int n, int m) {
    std::cout << "Массив n x m:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    srand(time(nullptr));
    int n, m;
    std::cout << "Введите количество строк (n): ";
    std::cin >> n;
    if (std::cin.fail() || n <= 0) {
        std::cout << "Ошибка: введите положительное целое число для количества строк.\n";
        return 1;
    }
    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;
    if (std::cin.fail() || m <= 0) {
        std::cout << "Ошибка: введите положительное целое число для количества столбцов.\n";
        return 1;
    }
    int** arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }
    char choice;
    std::cout << "Введите 'r' для заполнения массива случайными числами или 'i' для ввода с клавиатуры: ";
    std::cin >> choice;

    if (choice == 'r') {
        fillArrayRandom(arr, n, m);
    } else if (choice == 'i') {
        fillArrayInput(arr, n, m);
    } else {
        std::cout << "Некорректный выбор. Введите 'r' или 'i'.\n";
        return 1;
    }
    printArray(arr, n, m);

    for (int i = 0; i < n; ++i) {  
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}

