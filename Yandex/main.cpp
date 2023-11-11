#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define ll long long

#define LOCAL


void solve() {
  int n, m;
  cin >> m >> n;
  int sst = 0;
  while (n && m) {
    sst = sst % 3;
    if (sst == 2) {
      m--;
      cout << 'B';
    } else {
      n--;
      cout << 'G';
    }
    sst++;
  }
  while (m--) {
    cout << 'B';
  }
  while (n--) {
    cout << 'G';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(20);

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;

  while (t--) {
    solve();
  }
}
