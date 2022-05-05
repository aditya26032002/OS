#include <iostream>
using namespace std;

void best_fit(int main_memory[], int size_main, int processes[], int size_process){
    int allocation[size_process];
   
    for(int i = 0; i<size_process; i++){
        allocation[i] = -1;
    }

    for (int i=0; i<size_process; i++)
    {
        int best_id = -1;
        for (int j=0; j<size_main; j++)
        {
            if (main_memory[j] >= processes[i])
            {
                if (best_id == -1)
                    best_id = j;
                else if (main_memory[best_id] > main_memory[j])
                    best_id = j;
            }
        }
        if (best_id != -1)
        {
            allocation[i] = best_id;
            cout<<"Process No."<<i+1<<" allocated to Block No."<< best_id + 1 <<endl;
            main_memory[best_id] -= processes[i];
            cout << "Remaining memory size of block " << best_id + 1 << " is " << main_memory[best_id] << endl << endl;
        }
    }

    cout << "Process No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < size_process; i++)
    {
        cout << i+1 << "\t\t" << processes[i] << "\t\t";
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

int main()
{
    int main_memory[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int size_main = sizeof(main_memory) / sizeof(main_memory[0]);
    int size_process = sizeof(processes) / sizeof(processes[0]);

    best_fit(main_memory, size_main, processes, size_process);

    // int size_main, size_process;

    // cout<<"Enter no. of blocks of Main memory: ";
    // cin>>size_main;
    // int main_memory[size_main];

    // cout<<"Enter no. of processes: ";
    // cin>>size_process;
    // int processes[size_process];

    // cout<<"Enter sizes of main memory blocks:\n";
    // size_allocator(main_memory, size_main);

    // cout<<"Enter size of processes:\n";
    // size_allocator(processes, size_process);

    // best_fit(main_memory, size_main, processes, size_process);
    return 0;
}
