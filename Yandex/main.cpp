#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll fast_pow(ll x, int n, int mod) {
  if (!n)
    return 1;

  if (n % 2)
    return x * fast_pow(x, n - 1, mod) % mod;

  ll t = fast_pow(x, n/2, mod) % mod;
  return t * t % mod;
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
