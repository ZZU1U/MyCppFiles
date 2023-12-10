#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

vector<int> bliz_sleva(vector<tuple<int, bool, int>>& dots, int n) { // Sorted bool - is_start
  vector<int> ans(n);
  int li = -1;
  for (int i = 0; i < dots.size(); i++) {
    if (get<1>(dots[i])) {
      ans[get<2>(dots[i])] = li;
    } else {
      li = i;
    }
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;

  vector<int> c(n);
  vector<tuple<int, bool, int>> dots;

  for (int i = 0; i < n; i++) {
    int t, g;
    cin >> t;
    dots.emplace_back(t, true, i);
    cin >> g;
    dots.emplace_back(t+g, false, i);
    cin >> c[i];
  }

  auto ans = bliz_sleva(dots, n);

  vector<int> dp = {0};
  for (int i = 0; i < n; i++) {
    dp.push_back(max(dp[i], c[i] + (ans[i] == -1 ? 0 : dp[ans[i]])));
  }

  cout << dp.back();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
