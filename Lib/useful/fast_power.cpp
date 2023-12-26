#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll fast_pow(ll x, int n) {
  if (!n)
    return 1;

  if (n % 2)
    return x * fast_pow(x, n - 1);

  ll t = fast_pow(x, n/2);
  return t * t;
}

void solve() {
  cout << fast_pow(2, 10);
}

int main() {
  cout << fixed << setprecision(12);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
