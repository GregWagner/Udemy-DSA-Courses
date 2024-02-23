#include <iostream>

void printArray(std::string name, int a[], int size)
{
    std::cout << name << ": (" << size << ") ";
    for (int i {}; i < size; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

void merge()
{

}

void merge_sort(int a[], int startingIndex, int endingIndex)
{
    if (endingIndex - startingIndex <= 1) {
        std::cout << "Done\n";
        return;
    }
    int middle = (startingIndex + endingIndex) / 2;
    std::cout << startingIndex << ", " << middle << ", " << endingIndex << '\n';

    // create 2 new arrays
    int left[100];
    int i {};
    while (i < middle) {
        left[i] = a[i];
        ++i;
    }
    printArray("Left", left, middle);

    int right[100];
    i = 0;
    int index {middle};
    while (index < endingIndex) {
        right[i++] = a[index++];
    }
    printArray("Right", right, i);

    merge_sort(left, 0, endingIndex - middle);
    merge_sort(right, 0, i);
    merge(left:q);
}

void  merge(int left[], int right[], int result[], int startingIndex, int endingIndex)
{
}

int main()
{
    int a[] {9, 3, 6, 3, 1, 7, 2, 11};
    merge_sort(a, 0, 8);
    printArray("Done", a, 8);


}
