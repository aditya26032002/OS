#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int num;
    cout << "Enter num of processes: ";
    cin >> num;
    int bt[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter burst time of process " << i + 1 << " : ";
        cin >> bt[i];
    }

    int t_slice;
    cout << "Enter time quantum: ";
    cin >> t_slice;

    int wait[num], tat[num], rem_bt[num], total_wt = 0, total_tat = 0, c_time = 0;
    wait[0] = 0;
    for (int i = 0; i < num; i++)
    {
        rem_bt[i] = bt[i];
    }
    while (1)
    {
        bool isdone = true;
        for (int i = 0; i < num; i++)
        {

            if (rem_bt[i] > 0)
            {
                isdone = false;
                if (rem_bt[i] > t_slice)
                {
                    c_time += t_slice;
                    rem_bt[i] -= t_slice;
                }
                else
                {
                    c_time += rem_bt[i];
                    wait[i] = c_time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (isdone == true)
            break;
    }

    for (int i = 0; i < num; i++)
    {
        tat[i] = bt[i] + wait[i];
    }

    for (int i = 0; i < num; i++)
    {
        total_wt += wait[i];
        total_tat += tat[i];
    }

    cout << "Avg waiting time: " << (float)total_wt / num << "\n";
    cout << "Avg turn around time: " << (float)total_tat / num << "\n";

    return 0;
}