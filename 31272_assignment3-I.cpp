//selection sort using greedy search algorithm.

#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size;
    cout<<"Enter size of the array : ";
    cin>>size;

    int arr[size];

    for(int i = 0; i<size; i++){
        cout<<"Enter element "<<i+1<<" - ";
        cin>>arr[i];
    }

    cout<<"\nArray before selection sort "<<endl;
    printArr(arr, size);

    for (int i = 0; i < size - 1; i++)
    {
        int min = 999999, minIndex;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        int ele = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = ele;
    }

    cout<<"\n\nArray after selection sort "<<endl;
    printArr(arr, size);
    return 0;
}