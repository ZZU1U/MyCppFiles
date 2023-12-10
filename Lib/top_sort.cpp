#include <bits/stdc++.h>

using namespace std;

/*
 * This is a topological sort made with deep first search in c++
 *
 * In this algorithm we add our node to the answer, when we have passed all its kids
 *
 */

vector<int> ans;
vector<short> color;
vector<vector<int>> g;

void dfs(int v) { // Deep first search algorithm
  color[v] = 1;
  for (auto u : g[v]) {
    if (!color[u]) {
      dfs(u);
    } else if (color[u] == 1) {
      return;
    }
  }
  color[v] = 2;
  ans.push_back(v);
}

void solve() {
  int n, m;
  cin >> n >> m;

  color.resize(n);
  g.resize(n);

  for (int i = 0; i < m; i++) {
    int fr, to;
    cin >> fr >> to;
    g[--fr].push_back(--to);
  }

  dfs(0);

  if (ans.size() != n) {
    cout << "No";
  } else {
    reverse(ans.begin(), ans.end());
    cout << "Yes\n";
    for (auto i : ans) {
      cout << i + 1 << ' ';
    }
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
