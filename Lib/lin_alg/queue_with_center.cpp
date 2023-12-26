#include <iostream>
#include <deque>

using namespace std;

/*
 * This is a queue with ability of pasting an element in the center of queue
 * For this we have 2 deque
 */

void balance(deque<int> &fst, deque<int> &scd) { // This function make first and second just the same size (+- 1 for *)
  if (fst.empty() && scd.empty()) {
    return;
  }
  bool what_to_do = fst.size() > scd.size();
  int t;
  while (!(fst.size() == scd.size() || fst.size() == scd.size() + 1)) {
    if (what_to_do) {
      t = fst.back();
      fst.pop_back();
      scd.push_front(t);
    } else {
      t = scd.front();
      scd.pop_front();
      fst.push_back(t);
    }
  }
}

int main() {
  deque<int> first_half;
  deque<int> second_half;

  int n, t;
  char comma;

  cin >> n;

  for (int i = 0; i < n; i++) { // Some kind of interface
    cin >> comma;
    switch (comma) {
      case '-': {
        cout << first_half.front() << '\n';
        first_half.pop_front();
        break;
      }
      case '+': {
        cin >> t;
        second_half.push_back(t);
        break;
      }
      case '*': {
        cin >> t;
        first_half.push_back(t);
        break;
      }
      default: {
        break;
      }
    }
    balance(first_half, second_half);
  }
}
