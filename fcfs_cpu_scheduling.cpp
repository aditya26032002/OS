#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cout << "Enter number of processes"<<"\n";
    cin >> num;
    int arr[num];
    int wait[num];
    int TAT[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter burst time of process " << i + 1 << endl;
        cin >> arr[i];
    }
    int avgWT = 0, avgTAT = 0;
    wait[0] = 0;
    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            wait[i] += arr[j];
        }
    }
    for (int i = 0; i < num; i++)
    {
        TAT[i] = arr[i] + wait[i];
        avgWT += wait[i];
        avgTAT += TAT[i];
    }

    avgWT /= num;
    avgTAT /= num;

    cout << "Avg Waiting time: " << avgWT << "\n";
    cout << "Avg TA time: " << avgTAT << "\n";

    return 0;
}