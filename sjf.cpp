#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct process{
    char process_name;
    int priority;
    
}p[6];
int main()
{
    int num;
    cout << "Enter number of processes: ";
    cin >> num;
    int priority[num];
    int bt[num];
    int wait[num];
    wait[0] = 0;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter burst time of process : " << i + 1
             << "\n";
        cin >> bt[i];
    }

    sort(priority, priority + num);

    wait[0] = 0;
    for (int i = 1; i < num; i++)
    {
        wait[i] = wait[i - 1] + bt[i - 1];
    }

    int total_wt = 0;
    for (int i = 0; i < num; i++)
    {
        total_wt += wait[i];
    }
    cout << "Avg waiting time is " << total_wt / num << endl;

    int total_tat = 0;

    for (int i = 0; i < num; i++)
    {
        total_tat += wait[i] + bt[i];
    }
    cout << "Avg TA time is " << total_tat / num << "\n";

    return 0;
}