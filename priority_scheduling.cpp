#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct process{
    char process_name;
    int priority;
    int bt;
}p[6];

bool base(process p1, process p2){
    return (p1.priority > p2.priority);
}
int main()
{
    int num;
    cout << "Enter number of processes: ";
    cin >> num;
    process p[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter process name, priority, burst time of process " << i + 1 << " : ";
        cin >> p[i].process_name;
        cin >> p[i].priority;
        cin >> p[i].bt;
    }

    sort(p, p+num, base);

    cout<<"After sorting process will run as : ";
    for (int i = 0; i < num; i++)
    {
        cout<<p[i].process_name;
    }

    return 0;
}