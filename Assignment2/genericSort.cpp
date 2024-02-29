#include <iostream>

template <typename T>

//  struct Sample {
//         int id;
//         double value;
//     };
void merge(T arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    T* leftArray = new T[n1];
    T* rightArray = new T[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int N = 5;

    // Integer
    int intArr[N];
    std::cout << "Enter " << N << " integers: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> intArr[i];
    }
    mergeSort(intArr, 0, N - 1);
    std::cout << "Sorted integers: ";
    printArray(intArr, N);

    // Float
    float floatArr[N];
    std::cout << "Enter " << N << " float numbers: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> floatArr[i];
    }
    mergeSort(floatArr, 0, N - 1);
    std::cout << "Sorted float numbers: ";
    printArray(floatArr, N);

    // Double
    double doubleArr[N];
    std::cout << "Enter " << N << " double numbers: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> doubleArr[i];
    }
    mergeSort(doubleArr, 0, N - 1);
    std::cout << "Sorted double numbers: ";
    printArray(doubleArr, N);

   
    // Sample structArr[N];
    // std::cout << "Enter " << N << " struct values (id and value): ";
    // for (int i = 0; i < N; ++i) {
    //     std::cin >> structArr[i].id >> structArr[i].value;
    // }
   // mergeSort(structArr, 0, N - 1);
    //std:: cout << "Sorted struct: "";
    //printArray(structArr, N);

    return 0;
}
