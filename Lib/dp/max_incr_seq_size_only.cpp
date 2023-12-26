#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int INF = 100000;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (auto& i : a)
    cin >> i;

  vector<int> dp = {-INF};

  for (int i = 0; i < n; ++i) {
    auto iter = lower_bound(all(dp), a[i]);
    if (iter == dp.end())
      dp.push_back(a[i]);
    else
      *iter = a[i];
  }

  cout << dp.size() - 1 << '\n';

  for (int i = 1; i < dp.size(); i++) {
    cout << dp[i] << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  #endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
