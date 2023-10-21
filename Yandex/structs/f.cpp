#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, t;
  char c;
  cin >> n;

  queue<int> q1, q2;

  for (int i = 0; i < n; i++) {
    cin >> c;
    switch (c) {
      case '-': {
        cout << q1.front() << '\n';
        q1.pop();
        if (q2.size() > q1.size()) {
          q1.push(q2.front());
          q2.pop();
        }
        break;
      }
      case '+': {
        cin >> t;
        q2.push(t);
        break;
      }
      case '*': {
        cin >> t;
        q1.push(t);
        break;
      }
    }
    while (q2.size() > q1.size()) {
      q1.push(q2.front());
      q2.pop();
    }
  }
}
