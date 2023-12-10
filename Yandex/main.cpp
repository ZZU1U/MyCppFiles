#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define double long double

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (a > b)
    swap(a, b);

  while (a > 0) {
    b = b % a;
    swap(a, b);
  }

  return b;
}

void solve() {
  ll a, b;

  cin >> a >> b;

  cout << a * b / gcd(a, b);
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
