#include <iostream>
using namespace std;

void consumer();
int full = 0;
int empty = 5;
int lock = 0;

bool test_and_set(int &target){
    int rv = target;
    target = 1;
    return rv;
}

void wait(int empty){
    while(empty < 0);
    empty--;
}

void wait_m(int &lock){
    do{
        while(test_and_set(lock));
        return;
    } while (true);
}

void signals(int &full){
    full++;
}

void signals_emp(int &empty){
    empty--;
}

void signals_full(int &full){
    full--;
}

void producer(){
    do{
        wait(empty);
        wait_m(lock);
        
        cout<< "Data added to buffer\n";
        wait_m(lock);
        signals(full);
        signals_emp(empty);
        cout<<"Full = "<<full<<"\n empty = "<<empty<<endl;
        consumer();
        break;
    } while(true);
}

void consumer(){
    do{
        wait(full);
        wait_m(lock);

        cout<<"Data removed from buffer\n";
        signals_emp(lock);
        signals(empty);
        signals_full(full);
        cout<< "Empty = "<<empty<<"\n Full = "<< full<< endl;
        break;
    } while(true);
}

int main(){
    producer();
    return 0;
}