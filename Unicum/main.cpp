#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define double long double

using namespace std;

typedef long long ll;

void solve() {
  for (int i = 1; i < 10000; i++) {
    if (!(i & (i-1))) cout << i << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
//  cin >> t;

  while (t--) {
    solve();
  }
}
