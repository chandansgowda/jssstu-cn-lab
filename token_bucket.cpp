#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {
  int tokens = 1; // initial number of tokens in the bucket
  int rate = 10; // rate at which tokens are added to the bucket
  int capacity = 100; // maximum number of tokens the bucket can hold

  while (true) {
    // add tokens to the bucket at a fixed rate
    tokens = min(tokens + rate, capacity);

    // wait for 1 second
    this_thread::sleep_for(chrono::seconds(1));

    int request = 23; // number of tokens being requested
    if (tokens >= request) {
      // remove the requested tokens from the bucket
      tokens -= request;
      cout << "Request granted, tokens remaining: " << tokens << endl;
    } else {
      cout << "Request denied, not enough tokens: " << tokens << endl;
    }
  }

  return 0;
}
