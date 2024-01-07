#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;

using namespace std;

random_device rd;
mt19937 rng(rd());

int is_nice(vector<int>& v, const int& n) {
  int counter = 0;
  for (int i = 0; i < n; i++)
    for (int k = 0; k < i; k++) {
      counter += (v[i] == v[k]);
      counter += (abs(v[i] - v[k]) == i - k);
    }

  
  return counter;
}

void solve() {
  int n;
  cin >> n;

  vector<int> pos(n);
  iota(pos.begin(), pos.end(), 1);

  int last_res = 1e9;
  while (true) {
    int si = 1, sj = 1;
    si = rng() % n;
    sj = rng() % n;

    swap(pos[si], pos[sj]);

    int res = is_nice(pos, n);

    if (!res) {
      for (auto& i : pos) {
        cout << i << ' ';
      }
      return;
    }

    if (last_res > res) {
      last_res = res;
      cout << res;
    } else {
      swap(pos[si], pos[sj]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(24);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
