#include <iostream>

using namespace std;

void swap(int *array, int startPosition, int minPosition)
{
    int temp = array[startPosition];
    array[startPosition] = array[minPosition];
    array[minPosition] = temp;
}

void SelectionSort(int *array, int size)
{
    for (int startPosition = 0; startPosition < size; startPosition++)
    {
        int minPosition = startPosition;
        for (int i = minPosition + 1; i < size; i++)
        {
            if (array[i] < array[minPosition])
                minPosition = i;
        }

        swap(array, startPosition, minPosition);
    }
}

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    std::cout<<"Enter size of array: ";
    std::cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
        cin>>array[i];

    // int array[] = {0, 50, 90, 90, 1200, -40, 20, 60, -1500};
    // int n = sizeof(array) / sizeof(array[0]);

    cout << "Array before sorting: ";
    display(array, n);
    SelectionSort(array, n);
    cout << "Array after sorting: ";
    display(array, n);

    return 0;
}