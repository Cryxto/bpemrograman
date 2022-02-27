#include <iostream>
using namespace std;

void tukar(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partisi(int data[], int low, int high)
{
    int pivot = data[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (data[j] < pivot)
        {
            i++;
            tukar(&data[i], &data[j]);
        }
    }
    tukar(&data[i + 1], &data[high]);
    return (i + 1);
}

void quickSort(int data[], int low, int high)
{
    if (low < high)
    {
        int pi = partisi(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

void printdataay(int data[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (i % 25 == 0 && i != 0)
        {
            cout << data[i] << "\n ";
        }
        else
        {
            cout << data[i] << " ";
        }
    }
}

int main()
{
    int data[100];
    int search;
    int counter = 0;
    cout<<"\n=== PROGRAM QUICK SORT SEDERHANA DENGAN ANGKA ACAK ==="<<endl;
    cout << "\nGenerate data dengan angka acak...... \n ";
    for (int i = 0; i < 100; i++)
    {
        data[i] = 1 + (rand() % 100);
        if (i % 25 == 0 && i != 0)
        {
            cout << data[i] << "\n ";
        }
        else
        {
            cout << data[i] << " ";
        }
    }
    int n = sizeof(data) / sizeof(data[0]);
    quickSort(data, 0, n - 1);
    cout<<endl;
    cout << "\nData dalam array yang sudah di sort dengan quick sort : \n ";
    printdataay(data, n);
    return 0;
}
