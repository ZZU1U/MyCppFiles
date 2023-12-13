#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define double long double

using namespace std;

typedef long long ll;


tuple<int, int, int> evklid_extended(int a, int b) {
  // solves ax + by = d for specified a, b and d = gcd(x, y)
  // return x, y, d
  if (b == 0)
    return {1, 0, a};

  auto [x, y, d] = evklid_extended(b, a % b);

  return {y, x - a / b * y, d};
}

void solve() {
  int a, b;
  cin >> a >> b;

  auto [x, y, d] = evklid_extended(a, b);

  cout << x << ' ' << y << ' ' << d;
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
    cout << '\n';
  }
}
