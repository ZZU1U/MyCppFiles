#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> dp;
const ll INF = 1000001;
ll n;

void floyd() {
  for (ll k = 0; k < n; k++) {
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        if (max(dp[i][k], dp[k][j]) != INF && dp[i][j] > dp[i][k] + dp[k][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
        }
      }
    }
  }
}

void solve() {
  ll m;
  cin >> n >> m;
  dp.resize(n, vector<ll>(n, INF));

  for (ll i = 0; i < m; i++) {
    ll fr, to, w;
    cin >> fr >> to >> w;
    fr--;
    to--;
    dp[fr][to] = min(w, dp[fr][to]);
  }

  for (ll i = 0; i < n; i++)
    dp[i][i] = 0;

  floyd();

  for (auto i : dp) {
    for (auto j : i) {
      cout << (j == INF ? 30000 : j) << ' ';
    }
    cout << '\n';
  }
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
