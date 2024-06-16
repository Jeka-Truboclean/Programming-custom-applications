#include <iostream>
using namespace std;

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}

void BubbleSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (comparisonFcn(array[j], array[j + 1]))
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void printArray(int* array, int size)
{
    for (int index = 0; index < size; ++index)
        cout << array[index] << " ";
    cout << '\n';
}

int main()
{
    int array[8] = { 4, 8, 5, 6, 2, 3, 1, 7 };
    BubbleSort(array, 8, descending);
    printArray(array, 8);
}
