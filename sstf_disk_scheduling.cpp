#include <bits/stdc++.h>
using namespace std;

// {82,170,43,140,24,16,190}

int main()
{
    int size, seek_time=0;
    cout << "Enter num of files : ";
    cin >> size;

    int head;
    cout << "Enter current head location : ";
    cin >> head;

    int files[size];
    cout << "Enter location of files : ";
    for (int i = 0; i < size; i++)
    {
        cin >> files[i];
    }

    int seek[size];
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        int min = INT_MAX;
        int value, index;
        for (int j = 0; j < size; j++)
        {
            value = abs(files[j] - head);
            if (min > value)
            {
                min = value;
                index = j;
            }
        }
        sum += min;
        head = files[index];
        files[index] = INT_MAX;
        seek[i] = min;
    }

    cout<<"Individual seek time : ";
    for (int i = 0; i < size; i++)
    {
        cout << seek[i] << " ";
        seek_time += seek[i];
    }
    cout << "\n";

    cout << "Avg seek time = " << (double)sum / size << "\n";
    cout<< "Total seek time = "<<seek_time;
    return 0;
}