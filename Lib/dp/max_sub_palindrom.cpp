#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()

void solve() {
  string str;
  cin >> str;

  auto n = str.length();

  vector<vector<int>> dp(n, vector<int>(n));
  vector<vector<vector<int>>> chrs(n, vector<vector<int>>(n));

  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
    chrs[i][i].push_back(i);
  }

  int bl = 0, br = 0;

  for (int len = 1; len < n; len++) {
    for (int l = 0; l + len < n; l++) {
      auto r = l + len;
      if (dp[l][r-1] > dp[l][r]) {
        dp[l][r] = dp[l][r-1];
        chrs[l][r] = chrs[l][r-1];
      }

      if (dp[l+1][r] > dp[l][r]) {
        dp[l][r] = dp[l+1][r];
        chrs[l][r] = chrs[l+1][r];
      }

      if (str[l] == str[r] && dp[l+1][r-1] + 2 > dp[l][r]) {
        dp[l][r] = dp[l+1][r-1] + 2;
        chrs[l][r] = chrs[l+1][r-1];
        chrs[l][r].push_back(l);
        chrs[l][r].push_back(r);
      }

      if (dp[l][r] > dp[bl][br]) {
        bl = l;
        br = r;
      }
    }
  }

  // for (const auto& i : dp) {
  //   for (const auto& j : i)
  //     cout << j;
  //   cout << '\n';
  // }

  auto wrds = chrs[bl][br];
  sort(all(wrds));

  cout << dp[bl][br] << '\n';

  for (auto i : wrds)
    cout << str[i];
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  #endif

  solve();
}
