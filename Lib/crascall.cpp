#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int ans = 0;
const int INF = 10000000;
vector<tuple<int, int, int>> e;
vector<int> p;
vector<vector<int>> s;

int get(int u) {
  return p[u];
}

void uni(int u, int v) {
  if (s[u].size() < s[v].size()) {
    swap(u, v);
  }

  while (!s[v].empty()) {
    auto t = s[v].back();
    s[v].pop_back();
    p[t] = u;
    s[u].push_back(t);
  }
}

void min_ost() {
  sort(e.begin(), e.end());

  for (auto [w, u, v] : e) {
    if (get(u) != get(v)) {
      ans = w;
      uni(p[u], p[v]);
    }
  }
}

void solve() {
  cin >> n >> m;

  p.resize(n);
  s.resize(n);
  e.resize(m);

  for (int i = 0; i < n; i++) {
    p[i] = i;
    s[i] = {i};
  }

  int i = 0;
  for (auto& [w, fr, to] : e) {
    cin >> fr >> to;
    w = i++;
  }

  min_ost();

  cout << ans+1;
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
