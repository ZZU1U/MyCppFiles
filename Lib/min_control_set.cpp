#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

vector<vector<ll>> lg; // Ребра из L в R
vector<ll> rg;
vector<bool> used_r, used_l; // очев
int m, n;

void dfs(int v, bool is_r) {
  if (is_r) {
    if (used_r[v])
      return;

    used_r[v] = true;

    dfs(rg[v], !is_r);
  } else {
    if (used_l[v])
      return;

    used_l[v] = true;

    for (unsigned int i = 0; i < lg[v].size(); i++) {
      if (rg[lg[v][i]] != v) {
        dfs(lg[v][i], !is_r);
      }
    }
  }
}

void solve() {
  cin >> m >> n;

  lg.resize(m);
  rg.resize(n);
  used_l.resize(m);
  used_r.resize(n);

  for (int i = 0; i < m; i++) {
    int l;
    cin >> l;

    lg[i].resize(l);

    for (auto& j : lg[i]) {
      cin >> j;
      j--;
    }
  }

  vector<int> unvisited;

  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    t--;

    if (t >= 0)
      rg[t] = i;
    else
      unvisited.push_back(i);
  }

  for (auto i : unvisited) {
    dfs(i, false);
  }

  vector<int> ans_r;
  vector<int> ans_l;

  for (int i = 0; i < n; i++) {
    if (used_r[i])
      ans_r.push_back(i + 1);
  }
  cout << '\n';

  for (int i = 0; i < m; i++) {
    if (!used_l[i])
      ans_l.push_back(i + 1);
  }

  cout << ans_l.size() + ans_r.size() << '\n';

  cout << ans_l.size() << ' ';
  for (auto i : ans_l)
    cout << i << ' ';

  cout << '\n';

  cout << ans_r.size() << ' ';
  for (auto i : ans_r)
    cout << i << ' ';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  ll t = 1;
  // cin >> t;

  while (t--)
    solve();
}
