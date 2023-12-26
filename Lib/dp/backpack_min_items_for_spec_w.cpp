#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e8;

void solve() {
  ll n, m;

  cin >> n >> m;

  vector<ll> w(n + 1);

  for (ll i = 1; i <= n; cin >> w[i++]) { }

  vector<ll> d(m + 1, INF);
  d[0] = 0;

  for (ll i = 1; i <= n; i++) {
    for (ll j = m; j >= 1; j--) {
//      cout << w[i] << ' ' << j << ' ' << d[i-w[j]] << '\n';
      if (w[i] <= j && d[j - w[i]] != INF) {
        d[j] = min(d[j - w[i]] + 1, d[j]);
      }
    }
  }

  cout << (d.back() == INF ? 0 : d.back());
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
