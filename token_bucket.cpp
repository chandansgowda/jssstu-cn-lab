#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {
  int tokens = 0; // initial number of tokens in the bucket
  int rate = 10; // rate at which tokens are added to the bucket
  int capacity = 100; // maximum number of tokens the bucket can hold

  int request[100];
  
  int n;
  cout<<"Enter number of requests: ";
  cin>>n;
  
  cout<<"Enter no. of packets per request: ";
  for (int i=0;i<n;i++){
      cin>>request[i];
  }

  for (int i=0;i<n;i++) {
    // add tokens to the bucket at a fixed rate
    tokens = min(tokens + rate, capacity);

    // wait for 1 second
    this_thread::sleep_for(chrono::seconds(1));

    if (tokens >= request[i]) {
      // remove the requested tokens from the bucket
      tokens -= request[i];
      cout << "Request granted, tokens remaining: " << tokens << endl;
    } else {
      cout << "Request denied, not enough tokens: " << tokens << endl;
    }
  }

  return 0;
}
