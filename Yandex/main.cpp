#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n, t, counter;
  bool iscorrect = true;
  cin >> n;

  queue<int> in;
  stack<int> out;
  stack<int> crossroad;
  vector<int> actions;


  for (int i = 0; i < n; i++) {
    cin >> t;
    in.push(t);
  }


  while (!in.empty()) {
    counter = 0;

    while (!in.empty() && (crossroad.empty() || in.front() < crossroad.top())) {
      crossroad.push(in.front());
      in.pop();
      counter++;
    }

    actions.push_back(counter);
    counter = 0;

    while (!crossroad.empty() && (out.empty() || crossroad.top() > out.top())) {
      out.push(crossroad.top());
      crossroad.pop();
      counter++;
    }

    if (counter) {
      actions.push_back(counter);
      counter = 0;
    } else {
      iscorrect = false;
    }
  }
  if (iscorrect) {
    cout << actions.size() << '\n';
    for (int i = 0; i < actions.size(); i++) {
      cout << 1 + i % 2 << ' ' << actions[i] << '\n';
    }
  } else {
    cout << 0;
  }
}

