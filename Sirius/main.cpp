#include <iostream>
#include <stack>

using namespace std;

// Minimum in order 
// Realized with two stacks

int main() {
  stack<int> stadd;
  stack<int> stdel;

  int pop() {
    if (stdel.empty()) {
      while (!stadd.empty()) {
        t = stadd.top();
        stdel.push(t);
        stadd.pop();
      }
    }
  }
}
