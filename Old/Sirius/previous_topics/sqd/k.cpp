#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, q;

  cin >> n >> q;

  map<int, int> m;

  for (int i = 1; i <= n; i++) {
    m[i] = i;
  }

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;

    if (t == 1) {
      int a, b;
      cin >> a >> b;
      for (auto& j : m) {
        if (j.second == a) {
          j.second = j.first;
        }
      }
      m[b] = a;
    } else {
      int a;
      cin >> a;
      while (m[a] != a) {
        a = m[a];
      }
      cout << a << '\n';
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
