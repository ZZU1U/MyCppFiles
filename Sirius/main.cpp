#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
  if (get<1>(t1) < get<1>(t2)) {
    return true;
  }
  if (get<1>(t1) == get<1>(t2) && get<0>(t1) > get<0>(t2)) {
    return true;
  }
  return false;
}

void solve() {
  int n, cst;
  cin >> n;

  vector<tuple<int, int, int>> segments;
  for (int i = 0; i < n; i++) {
    int l, length;
    cin >> l >> length >> cst;

    segments.emplace_back(l, l+length, i);
  }

  sort(all(segments), cmp);

//  cout << '\n' << '\n';
//
//  for (auto [l, r, i] : segments) {
//    cout << l << ' ' << r << ' ' << i << '\n';
//  }

  vector<int> ans;

  int rend = -1000000;
  for (auto [l, r, i] : segments) {
    if (l >= rend) {
      ans.push_back(i);
      rend = r;
    }
  }
  cout << cst * ans.size() << '\n'<< ans.size() << '\n';
  for (auto i : ans) {
    cout << i + 1 << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
