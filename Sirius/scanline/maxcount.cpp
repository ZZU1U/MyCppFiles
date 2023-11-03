#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

void solve() {
  int n, m;

  cin >> n >> m;

  vector<pair<int, int>> dots(2 * n);

  for (int i = 0; i < 2 * n; i++) {
    int t;
    cin >> t;

    dots[i] = make_pair(t, (i % 2 ? 1 : -1));
  }

  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    dots.push_back(make_pair(t, 0));
  }

  sort(all(dots));


  int balance = 0;

  for (auto dt : dots) {
    balance -= dt.second;
    if (!dt.second) {
      cout << balance << ' ';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
}