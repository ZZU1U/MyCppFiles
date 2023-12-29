#include <bits/stdc++.h>

using namespace std;

typedef  long long ll;
#define all(x) x.begin(), x.end()

ll F(ll n) {
  ll res = 1;

  for (ll i = 2; i <= n; i++) {
    res = res * i;
  }

  return res;
}

ll A(ll n, ll k) {
  ll res = 1;
  for (ll i = 0; i < k; i++)
    res *= (n - i);

  return res;
}

ll C(ll n, ll k) {
  if (k > n)
    return 0;

  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    }
  }

  return dp.back().back();
}

void solve() {
  ll n, m, t;
  cin >> n >> m >> t;

  ll ans = 0;

  for (int mens = 4; mens + 1 <= t; mens++) {
    ans += C(n, mens) * C(m, t - mens);
  }

  cout << ans;
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  #endif

  int t = 1;

  while (t--) {
    solve();
    cout << '\n';
  }
}
