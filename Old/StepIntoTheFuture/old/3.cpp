#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

ll f(ll n) {
  return n * n;
}

void sieve(ll beg, ll n, vector<ll>& p, vector<ll>& ans) {
  beg = abs(beg);
  n = abs(n);

  p.resize(n);

  for (ll i = beg; i <= n; i++) {
    if (!p[i]) {
      p[i] = i;
      ans.push_back(i);
    }

    for (ll j = 0; j < ans.size() && ans[j] * i <= n; j++) {
      p[ans[j] * i] = min(p[i], (p[j*i] ? min(ans[j], p[j * i]) : ans[j]));
    }
  }
}

int get_simple_between(ll a, ll b, const vector<ll>& ans) {
  a = abs(a);
  b = abs(b);

  if (a > b)
    swap(a, b);

  return lower_bound(all(ans), b) - upper_bound(all(ans), a);
}

void solve() {
  int fuel, n;
  cin >> fuel >> n;

  ll x=0, y=0;

  short int wg = 0;

//   3
// 2 + 0
//   1

  ll counter = 0;
  
  vector<ll> p = {0, 0};
  vector<ll> ans;

  for (int i = 0; i < n; i++) {
    string comma;
    int l;

    cin >> comma >> l;

    if (f(l) > fuel)
      continue;

    fuel -= f(l);

    if (comma == "Left") {
      wg = (wg + 3) % 4;
    } else {
      wg = (wg + 1) % 4;
    }

    if (wg % 2) {
      ll ny = y + (wg - 2) * l;

      if (abs(x) + abs(ny) >= p.size()) {
        sieve(p.size(), x + ny, p, ans);
      }

      counter += get_simple_between(x + y, x + ny, ans);
      y = ny;
    } else {
      ll nx = x - (wg - 1) * l;

      if (abs(y) + abs(nx) >= p.size()) {
        sieve(p.size(), y+ nx, p, ans);
      }

      counter += get_simple_between(x + y, nx + y, ans);
      x = nx;
    }

    cout << x << ' ' << y << ' ' << counter << '\n';
  }

  cout << counter;
}

int main() {
  cout.tie(nullptr);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  #endif

  solve();
}
