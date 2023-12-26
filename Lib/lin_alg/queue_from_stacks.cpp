#include <iostream>
#include <stack>

using namespace std;

/*
 * The hardest thing to understand is that
 * We only put new items in second stack when it's already empty
 * And we need to pop another one
 */

// If we want to know min we calcul as in stack when we add and when we move to pop_stack

struct que {
  stack<int> stadd;
  stack<int> stdel;

  int pop() {
    int t;
    if (stdel.empty()) { // So if our deleting stack is empyt
      while (!stadd.empty()) { // We add new elemnts from input stack
        t = stadd.top();
        stdel.push(t);
        stadd.pop();
      }

      if (stdel.empty()) { // If it's steel empty
        return -1; // There should be an exception...
      }
    }

    t = stdel.top(); // Than we just grab the last item
    stdel.pop(); // Delete it

    return t; // And send it
  }

  void push(int item) {
    stadd.push(item);
  }
};

int main() {
  int n, t;

  cin >> n;

  que q;

  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t == 0) {
      cout << q.pop();
    } else {
      q.push(t);
    }
  }
}
