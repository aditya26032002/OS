#include <iostream>
using namespace std;

int i=0;
int j = 1-i;
int turn;
bool flag[2] = {false, false};

void process2();

void cs(int i){
    cout<<"P"<<i+1<<" in critical section.\n";
}

void process1(){
    while(1){
        flag[i] = true;
        turn = j;

        while(turn==i && flag[i]);
        cs(i);
        flag[i] = false;
        process2();
    }
}

void process2(){
    while(1){
        flag[j] = true;
        turn = i;

        while(turn==i && flag[i]);
        cs(j);
        flag[i] = false;
        process1();
    }
}

int main(){
    process1();
    return 0;
}