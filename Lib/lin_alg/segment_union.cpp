#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

/*
 * This is code for collapsing segments that overlaps each over to a signle segment
 *
 * Input is number of segments and their cords
 *
 * Output is number of collapsed segments and their cords
 *
 */

using namespace std;

void solve() {
  int n;

  cin >> n;

  vector<pair<int, int>> dots(2 * n);

  for (int i = 0; i < 2 * n; i++) {
    int t;
    cin >> t;

    dots[i] = make_pair(t, (i % 2 ? 1 : -1));
  }

  sort(all(dots));

  vector<pair<int, int>> segments;

  int last_l = dots[0].first;
  bool ll = true;
  int balance = 0;

  for (auto dt : dots) {
    balance -= dt.second;
    if (balance == 0) {
      if (!ll) {
        last_l = dt.first;
        ll = true;
      } else {
        segments.emplace_back(last_l, dt.first);
        ll = false;
      }
    } else if (balance + dt.second == 0 && !ll) {
      last_l = dt.first;
      ll = true;
    }
  }

  cout << segments.size();
  for (auto [l, r] : segments) {
    cout << '\n' << l << ' ' << r;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  solve();
}
