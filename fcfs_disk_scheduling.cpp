#include <iostream>
using namespace std;
//  = {82,170,43,140,24,16,190}
int main()
{
    int num_processes, current_position, seek_time = 0;
    cout << "Enter number of processes : ";
    cin >> num_processes;

    int position[num_processes], indiv_seek_time[num_processes];
    cout << "Enter current position : ";
    cin >> current_position;

    for (int i = 0; i < num_processes; i++)
    {
        cout << "Enter position of process " << i + 1 << " : ";
        cin >> position[i];
    }

    for (int i = 0; i < num_processes; i++)
    {
        indiv_seek_time[i] = position[i] - current_position;
        if (indiv_seek_time[i] < 0)
        {
            indiv_seek_time[i] = (-indiv_seek_time[i]);
        }
        seek_time += indiv_seek_time[i];
        current_position = position[i];
    }
    cout << "Seek time of individual processes are : ";
    for (int i = 0; i < num_processes; i++)
    {
        cout << indiv_seek_time[i] << " ";
    }
    cout << "\nTotal seek time = " << seek_time;
    return 0;
}