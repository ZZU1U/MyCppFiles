#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int INF = 100000;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a)
    cin >> i;

  int m;
  cin >> m;
  vector<int> b(m);
  for (auto& i : b)
    cin >> i;

  vector<vector<int>> dp(n+1, vector<int>(m+1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i-1] == b[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << dp.back().back() << '\n';
  int i = n, j = m;
  vector<int> ans;
  while (i && j) {
    if (a[i-1] == b[j-1]) {
      ans.push_back(a[i-1]);
      i--;
      j--;
    } else {
      if (dp[i-1][j] > dp[i][j-1]) {
        i--;
      } else {
        j--;
      }
    }
  }
  reverse(all(ans));

  for (auto num : ans) {
    cout << num << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
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
