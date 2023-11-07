#include <iostream>
#include <iomanip>
#include <time.h>

int** Create(int** arr, const int n, const int low, const int high, int i, int j) {
    if (i == n) {
        return arr;
    }
    if (j == n) {
        return Create(arr, n, low, high, i + 1, 0);
    }
    arr[i][j] = low + rand() % (high - low + 1);
    return Create(arr, n, low, high, i, j + 1);
}

void TransposeMatrix(int** arr, const int n, int i, int j) {
    if (i == n) {
        return;
    }
    if (j == n) {
        return TransposeMatrix(arr, n, i + 1, i + 1);
    }

    int temp = arr[i][j];
    arr[i][j] = arr[j][i];
    arr[j][i] = temp;
    TransposeMatrix(arr, n, i, j + 1);
}

void Print(int** arr, const int n, int i, int j) {
    if (i == n) {
        std::cout << std::endl;
        return;
    }
    if (j == n) {
        std::cout << std::endl;
        Print(arr, n, i + 1, 0);
        return;
    }
    std::cout << std::setw(4) << arr[i][j];
    Print(arr, n, i, j + 1);
}

int main() {

    int low = 1;
    int high = 50;
    const int n = 6;

    srand((unsigned)time(NULL));

    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    Create(arr, n, low, high, 0, 0);
    Print(arr, n, 0, 0);
    TransposeMatrix(arr, n, 0, 0);
    Print(arr, n, 0, 0);

    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}
