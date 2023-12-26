#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1000000;

void solve() {
  int n, m;

  cin >> n >> m;

  vector<int> w(n+1);

  for (int i = 1; i <= n; i++)
    cin >> w[i];

  vector<int> d(m+1, 0);

  for (auto j = 1; j <= n; j++) {
    for (int i = m; i > 0; i--) {
      if (w[j] <= i) {
//        cout << i << '-' << i-w[j] << '\n';
        d[i] = max(d[i], d[i-w[j]] + w[j]);
      }
    }
  }

  cout << d.back();
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifdef DEBUG
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  solve();
}
