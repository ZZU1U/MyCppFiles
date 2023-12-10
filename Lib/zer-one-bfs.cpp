#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<int, bool>>> g;
int n;
vector<int> dist;

void bfs(int fr) {
  dist[fr] = 0;
  deque<int> d;

  d.push_back(fr);

  while (!d.empty()) {
    auto v = d.front();
    d.pop_front();
    for (auto [u, w] : g[v]) {
      if (w + dist[v] < dist[u]) {
        dist[u] = dist[v] + w;
        if (w) {
          d.push_back(u);
        } else {
          d.push_front(u);
        }
      }
    }
  }
}


void solve() {
  cin >> n;
  int m;
  cin >> m;
  dist.resize(n, 10000);
  g.resize(n);

  for (int i = 0; i < m; i++) {
    int fr, to;
    bool w;
    cin >> fr >> to >> w;

    g[fr].emplace_back(to, w);
  }

  bfs(0);

  for (auto i : dist)
    cout << i;
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
