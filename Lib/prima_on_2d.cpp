#include <bits/stdc++.h>

using namespace std;

int n;
const double INF = 100000;
vector<pair<double, int>> mins;
vector<bool> mst;
vector<pair<int, int>> coords;
vector<pair<int, int>> ans;

double edge_weight(int a, int b) {
  auto [ax, ay] = coords[a];
  auto [bx, by] = coords[b];
  return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

void min_ost() {
  for (int i = 0; i < n; i++) {
    int mn = -1;
    for (int v = 0; v < n; 1v++) {
      if (!mst[v] && (mn == -1 || mins[mn] > mins[v])) {
        mn = v;
      }
    }

    if (mins[mn].second != -1)
      ans.emplace_back(mins[mn].second, mn);

    mst[mn] = true;

    for (int u = 0; u < n; u++) {
      if (!mst[u]) {
        mins[u] = min(mins[u], {edge_weight(u, mn), u});
      }
    }
  }
}

void solve() {
  cin >> n;
  mins.resize(n,  {INF, -1});
  mst.resize(n, false);
  coords.resize(n);

  for (auto& [x, y] : coords)
    cin >> x >> y;

  min_ost();

  double result = 0;
  for (auto [w, _] : mins)
    result += (w == INF ? 0 : w);

  cout << result;
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
