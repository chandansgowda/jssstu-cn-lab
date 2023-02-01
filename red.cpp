#include <iostream>
#include <time.h>
using namespace std;

int MAX_PACKETS = 20;
int QUEUE_SIZE = 10;
double MAX_PROBABILITY = 0.7;
double MIN_PROBABILITY = 0.3;


int main(){

    srand(time(0));
    int queue_length=0;
    double drop_probability = MIN_PROBABILITY;

    for(int i=0; i<MAX_PACKETS; i++){
        if (queue_length==QUEUE_SIZE){
            cout << "Packet dropped (QUEUE FULL)" <<endl;
            drop_probability = MIN_PROBABILITY;
        }
        else if ((double)rand()/RAND_MAX < drop_probability){
            cout << "Packet dropped (RANDOM)" <<endl;
            drop_probability += (MAX_PROBABILITY - MIN_PROBABILITY)/(MAX_PACKETS - 1);
        }
        else{
            cout << "Packet accepted" <<endl;
            queue_length++;
            drop_probability = MIN_PROBABILITY;
        }
    }

    return 0;
}