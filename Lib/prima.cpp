#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
const int INF = 10000000;
ll answer = 0;
vector<int> d;
set<pair<int, int>> work = {{0, 0}};
vector<vector<pair<int, int>>> e;

void min_ost() {
  d[0] = 0;
  while (!work.empty()) {
    auto [dist, v] = *work.begin();
    work.erase(work.begin());

    d[v] = -INF;
    answer += dist;

    for (auto [w, u] : e[v]) {
      if (w < d[u]) {
        work.erase({d[u], u});
        d[u] = w;
        work.insert({w, u});
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  e.resize(n);
  d.resize(n,  INF);

  for (int i = 0; i < m; i++) {
    int fr, to, w;
    cin >> fr >> to >> w;
    fr--;
    to--;
    e[fr].emplace_back(w, to);
    e[to].emplace_back(w, fr);
  }

  min_ost();

  cout << answer;
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
