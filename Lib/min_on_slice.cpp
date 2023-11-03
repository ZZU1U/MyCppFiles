#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);

  for (auto& i : v) {
    cin >> i;
  }

  deque<int> d;

  for (int i = 0; i < n; i++) {
    if (d.empty()) {
      d.push_back(i);
    }

    if (d.front() < i - k + 1) {
      d.pop_front();
    }

    while (!d.empty() && v[d.back()] >= v[i]) {
      d.pop_back();
    }

    d.push_back(i);

    if (i >= k - 1) {
      cout << v[d.front()] << ' ';
    }
  }


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
