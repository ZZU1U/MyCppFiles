#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<long long, long long>>> g;
vector<bool> used;
vector<long long> dp;
vector<long long> pr;
set<pair<long long, long long>> setd;

void dijkstra(long long start) {
  setd.insert({start, 0});
  dp[start] = 0;

  while (!setd.empty()) {
    auto v = setd.begin()->second;
    setd.erase(setd.begin());
    used[v] = true;

    for (auto [u, w] : g[v]) {
      if (!used[u]) {
        if (dp[u] > dp[v] + w || dp[u] == -1) {
          setd.erase({dp[u], u});
          dp[u] = dp[v] + w;
          setd.insert({dp[u], u});
          pr[u] = v;
        }
      }
    }
  }
}

void solve() {
  long long n, m;
  cin >> n >> m;
  dp.resize(n, -1);
  used.resize(n);
  pr.resize(n);
  g.resize(n);

  for (long long i = 0; i < m; i++) {
    long long start, end, weight;
    cin >> start >> end >> weight;
    start--;
    end--;
    g[start].emplace_back(end, weight);
    g[end].emplace_back(start, weight);
  }

  dijkstra(0);

  vector<long long> ans;

  auto lp = pr.back();

  if (dp.back() == -1) {
    cout << -1;
    return;
  }

  ans.push_back(n);
  while (lp != pr[lp]) {
    ans.push_back(lp + 1);
    lp = pr[lp];
  }
  ans.push_back(1);
  reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << ' ';
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
