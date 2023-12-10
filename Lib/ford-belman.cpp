#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 30000;
vector<ll> dp;
vector<tuple<ll, ll, ll>> g;

void ford_belman() {
  bool fl = true;

  while (fl) {
    fl = false;

    for (auto [fr, to, w] : g) {
      if (dp[fr] != INF && dp[to] > dp[fr] + w) {
        dp[to] = dp[fr] + w;
        fl = true;
      }
    }
  }
}

void solve() {
  ll n, m;
  cin >> n >> m;

  g.resize(m);
  dp.resize(n, INF);
  dp[0] = 0;

  for (auto& [fr, to, w] : g) {
    cin >> fr >> to >> w;
    fr--;
    to--;
  }

  ford_belman();

  for (auto l : dp) {
    cout << l << ' ';
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
