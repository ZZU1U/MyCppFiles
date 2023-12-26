#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() {
  int k, m, t, x;

  cin >> k >> m >> t >> x;

  int weeks = (m - x - t) / (7 * k - t);

  if (7 * k < t && 7 * k + x < m) {
    cout << -1;
    return;
  }

  cout << weeks * 7 + (m - x - weeks * (7 * k - t)) / k;
}

int main() {
  cout << fixed << setprecision(12);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  #endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
