#include <iostream>
using namespace std;

void first_fit(int main_memory[], int size_main, int processes[], int size_process)
{
    int allocation[size_process];

    for (int i = 0; i < size_process; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < size_process; i++)
    {
        for (int j = 0; j < size_main; j++)
        {
            if (main_memory[j] >= processes[i])
            {
                allocation[i] = j;
                cout<<"Process No."<<i+1<<" allocated to Block No."<< j+1<<endl;
                main_memory[j] -= processes[i];
                cout << "Remaining memory size of block " << j << " is " << main_memory[j] << endl << endl;
                break;
            }
        }
    }

    cout << "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < size_process; i++)
    {
        cout << i + 1 << "\t\t"
             << processes[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

void size_allocator(int Arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter size at position: " << i + 1 << " : ";
        cin >> Arr[i];
    }
}
// {100, 500, 200, 300, 600}
// {212, 417, 112, 426}

int main()
{
    int main_memory[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int size_main = sizeof(main_memory) / sizeof(main_memory[0]);
    int size_process = sizeof(processes) / sizeof(processes[0]);

    first_fit(main_memory, size_main, processes, size_process);

    //  int size_main, size_process;

    //  cout<<"Enter no. of blocks of Main memory: ";
    //  cin>>size_main;
    // int main_memory[size_main];

    //  cout<<"Enter no. of processes: ";
    //  cin>>size_process;
    // int processes[size_process];

    // cout<<"Enter sizes of main memory blocks:\n";
    // size_allocator(main_memory, size_main);

    // cout<<"Enter size of processes:\n";
    // size_allocator(processes, size_process);

    // first_fit(main_memory, size_main, processes, size_process);

    return 0;
}
