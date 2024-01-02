#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

vector<vector<int>> g; // Ребра из L в R
vector<int> mt; // пары верш
vector<int> used; // очев

bool try_kuhn(int v, int n) {
  if (used[v] == n)
    return false;

  used[v] = n;

  for (auto u : g[v]) {
    if (mt[u] == -1 || try_kuhn(mt[u], n)) {
      mt[u] = v;
      return true;
    }
  }

  return false;
}

void solve() {
  int n, m;
  int ans = 0;
  cin >> n >> m;

  g.resize(n);
  mt.resize(n, -1);
  used.resize(n, -1);

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    while (t) {
      g[i].push_back(t-1);
      cin >> t;
    }
  }

  for (int v = 0; v < n; v++) {
    if (try_kuhn(v, v))
      ans++;
  }

  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    if (mt[i] != -1)
      cout << i+1 << ' ' << mt[i]+1 << '\n';
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
