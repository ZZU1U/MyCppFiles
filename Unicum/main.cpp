#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define double long double

using namespace std;

typedef long long ll;

void solve() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  if (b > c)
    swap(b, c);

  if (a > b)
    swap(a, b);

  if (b > c)
    swap(b, c);

  if (e > f)
    swap(e, f);

  if (d > e)
    swap(d, e);

  if (e > f)
    swap(e, f);

  if (a == d && b == e && c == f) {
    cout << "Boxes are equal";
  } else if (a > d && b > e && c > f) {
    cout << "The first box is larger than the second one";
  } else if (a < d && b < e && c < f) {
    cout << "The first box is smaller than the second one";
  } else {
    cout << "Boxes are incomparable";
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
