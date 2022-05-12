#include <iostream>
using namespace std;

int main(){
    int current_position = 50, seek_time = 0, temp;
    int position[] = {82,170,43,140,24,16,190};
    int length_position = sizeof(position)/sizeof(position[0]);
    for(int i = 0; i<length_position; i++){
        temp = position[i] - current_position;
        if(temp <0){
            temp = (-temp);
        }
        seek_time += temp;
        current_position = position[i];
    }
    cout<<"Seek time = "<<seek_time;
    return 0;
}