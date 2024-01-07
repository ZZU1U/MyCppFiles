#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

vector<vector<ll>> g; // Ребра из L в R
vector<ll> p; // пары верш
vector<ll> mark; // очев

bool try_kuhn(ll v, ll n) {
  if (mark[v] == n) return false;

  mark[v] = n;

  for (auto u : g[v]) {
    if (p[u] == -1 || try_kuhn(p[u], n)) {
      p[u] = v;
      return true;
    }
  }

  return false;
}

void solve() {
  ll n, m;
  ll ans = 0;
  cin >> n >> m;

  g.resize(n);
  p.resize(m, -1);
  mark.resize(m, -1);

  for (ll i = 0; i < n; i++) {
    ll t;
    cin >> t;
    while (t) {
      g[i].push_back(t-1);
      cin >> t;
    }
  }

  for (ll v = 0; v < n; v++) {
    ans += try_kuhn(v, v);
  }

  cout << ans << '\n';

  for (ll i = 0; i < m; i++) {
    if (p[i] != -1)
      cout << p[i] + 1 << ' ' << i + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ll t = 1;
  // cin >> t;

  while (t--)
    solve();
}
