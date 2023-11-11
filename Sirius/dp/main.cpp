#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long
#define DEBUG

using namespace std;

void solveH() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& i : v)
    cin >> i;

  vector<int> prev_ind;
  vector<pair<int, int>> dp;
  vector<int> all_prev(n);

  for (int i = 0; i < n; i++) {
    auto ind = upper_bound(all(dp), make_pair(v[i], i));
    if (ind == dp.end()) {
      if (dp.empty()) {
        prev_ind.push_back(i);
      } else {
        prev_ind.push_back(dp.back().second);
      }
      all_prev[i] = prev_ind.back();
      dp.emplace_back(v[i], i);
    } else {
      *ind = make_pair(v[i], i);
      all_prev[i] = prev_ind[distance(dp.begin(), ind)];
    }
  }
  for (auto [a, b] : dp) {
    cout << a << ' ' << b << '\n';
  }
  vector<int> ans;
  cout << '\n';
  int ind = dp.back().second;
  while (all_prev[ind] != ind) {
    ans.push_back(v[ind]);
    ind = all_prev[ind];
  }
  ans.push_back(v[ind]);
  reverse(all(ans));
  for (auto i : ans) {
    cout << i << ' ';
  }
  // BRUH bro said <= and made > lmao
}

void solveI() {
  int n;
  cin >> n;

  vector<int> p(n);
  for (auto& i : p) {
    cin >> i;
  }

  int max_z = 0;
  for (int i = 0; i < n; i++) {
    auto t = upper_bound(all(p), 2 * p[i]);
    cout << p[i] << ' ' << *(t-1) << ' ' << *t << '\n';
    max_z = max(max_z, (int)distance(p.begin(), t) - i);
  }

  cout << max_z;
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  solveH();
}