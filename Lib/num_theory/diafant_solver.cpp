#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define double long double

using namespace std;

typedef long long ll;


tuple<int, int, int> evklid_ext(int a, int b) {
  // This algorithm has it's own file
  if (b == 0)
    return {1, 0, a};

  auto [x, y, d] = evklid_ext(b, a % b);

  return {y, x - a / b * y, d};
}

int gcd(int a, int b) {
  if (b > a)
    swap(a, b);

  while (b) {
    a = a % b;
    swap(a, b);
  }

  return a;
}

void solve() {
  // This is how to find a soltuion for diafant equation
  // in integers

  // ax + by = c for specified a, b, c

  int a, b, c;
  cin >> a >> b >> c;

  auto d = gcd(a, b);

  if (c % d) {
    cout << "Impossible";
    return;
  }

  a /= d;
  b /= d;
  c /= d;

  auto [x, y, z] = evklid_ext(a, b);

  cout << d << ' ' << x * c << ' ' << y * c;
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
