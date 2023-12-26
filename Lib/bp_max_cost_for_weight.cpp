#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1000000;

void solve() {
  int n, m;

  cin >> n >> m;

  vector<int> w(n+1);
  vector<int> c(n+1);

  for (int i = 1; i <= n; i++)
    cin >> w[i];

  for (int i = 1; i <= n; i++)
    cin >> c[i];

  vector<vector<int>> d(n+1, vector<int>(m+1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int t = 0;
      if (j >= w[i]) {
        t = d[i-1][j-w[i]] + c[i];
      }
      d[i][j] = max(d[i-1][j], t);
    }
  }

  int i = n;
  int j = m;

  vector<int> ans;

  while (i && j) {
    if (d[i-1][j] != d[i][j]) {
      j -= w[i];
      ans.push_back(i);
    }
    i--;
  }
  reverse(ans.begin(), ans.end());

  cout << ans.size() << '\n';

  for (auto i : ans)
    cout << i << ' ';
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifdef DEBUG
  freopen("./input.txt", "r", stdin);
//  freopen("./output.txt", "w", stdout);
#endif

  solve();
}
