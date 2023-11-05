#include<iostream>
#include <sys/time.h>

long getTimeInMicroSeconds() { 
    struct timeval currentTime;
    gettimeofday(&currentTime, nullptr);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void mergeArrays(int x[], int y[], int a[], int s, int e) {
    int mid {(s + e) / 2};
    int i {s};
    int j {mid + 1};
    int k {s};

    while (i <= mid && j <= e) {
        if (x[i] < y[j]) {
            a[k++] = x[i++];
        } else {
            a[k++] = y[j++];
        }
    }

    while (i <= mid) {
        a[k++] = x[i++];
    }
    while (j <= e) {
        a[k++] = y[j++];
    }
}

int *x = new int[10000000];
int *y = new int[10000000];

void mergeSort(int a[],int s,int e) {
    if (s >= e){
        return;
    }
    int mid {(s + e) / 2};

    for (int i {s}; i <= mid; i++) {
        x[i] = a[i];
    }
    for (int i {mid + 1}; i <= e; i++){
        y[i] = a[i];
    }
    mergeSort(x, s, mid);
    mergeSort(y, mid + 1, e);
    mergeArrays(x, y, a, s, e);
}

void selectionSort(int a[],int n){
    for (int i {}; i <= n - 2; ++i){
        int smallest {i};
        for (int j {i + 1}; j <= n - 1; ++j) {
            if (a[j] < a[smallest]) {
                smallest = j;
            }
        }
        std::swap(a[i], a[smallest]);
    }
}

int main() {
    for (int n{10}; n <= 10000000; n *= 10) {
        int *arr = new int[n];
        for (int i {}; i < n; i++) {
            arr[i] = n - i;
        }

        long startTime = getTimeInMicroSeconds();
        ///mergeSort(arr, 0, n-1);
        selectionSort(arr, n);
        long endTime = getTimeInMicroSeconds();

//      std::cout << "Merge sort n = " << n << "  time = " << endTime - startTime<< '\n';
        std::cout << "Selection sort n = " << n << " time = "
            << endTime-startTime << '\n';
        delete []arr;
    }
}
