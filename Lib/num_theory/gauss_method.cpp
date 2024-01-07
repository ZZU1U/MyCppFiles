#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ld EPS = 1e-16;

struct matrix {
  ll n, m;
  vector<vector<ld>> M;

  vector<ld>& operator [](ll i) {
    return this->M[i];
  }
};

istream& operator >> (istream& in, matrix& a) {
  a.M.resize(a.n, vector<ld>(a.m));

  for (auto& i : a.M)
    for (auto& j : i)
      in >> j;

  return in;
}

ostream& operator << (ostream& os, const matrix& a) {
  for (auto& i : a.M) {
    for (auto& j : i)
      os << j << ' ';
    os << '\n';
  }

  return os;
}

matrix operator - (matrix a, matrix b) {
  for (ll i = 0; i < a.n; i++)
    for (ll j = 0; j < a.m; j++)
      a[i][j] = (a[i][j] - b[i][j]);

  return a;
}

matrix operator + (matrix a, matrix b) {
  for (ll i = 0; i < a.n; i++)
    for (ll j = 0; j < a.m; j++)
      a[i][j] = (a[i][j] + b[i][j]);

  return a;
}

matrix operator * (matrix a, const ld k) {
  for (ll i = 0; i < a.n; i++) {
    for (ll j = 0; j < a.m; j++) {
      a[i][j] *= k;
    }
  }

  return a;
}

void solve() {
  ll n;
  cin >> n;

  matrix a = {n, n + 1};

  cin >> a;

  bool smth_wrong = false;

  for (ll cur_pos = 0; cur_pos < n; cur_pos++) {
    ll cor_line = cur_pos;
    for (ll line = cor_line + 1; line < n; line++) {
      if (abs(a[line][cur_pos]) > abs(a[cor_line][cur_pos]) ||
          abs(a[line].back()) < abs(a[cor_line].back()) &&
          abs(a[line][cur_pos] - a[cor_line][cur_pos]) < EPS)
        cor_line = line;
    }
    swap(a[cor_line], a[cur_pos]);

    if (abs(a[cur_pos][cur_pos]) >= EPS) {
      for (ll line = 0; line < n; line++) {
        if (line != cur_pos) {
          ld k = a[line][cur_pos] / a[cur_pos][cur_pos];

          for (ll i = 0; i <= n; i++)
            a[line][i] -= a[cur_pos][i] * k;
        }
      }
    } else {
      smth_wrong = true;
    }
  }

  vector<ld> ans(n);

  for (ll i = 0; i < n; i++) {
    if (abs(a[i][i]) < EPS) {
      if (abs(a[i].back()) > EPS) {
        cout << "impossible";
        return;
      } else {
        smth_wrong = true;
      }
    } else
      ans[i] = a[i].back() / a[i][i];
  }

  if (smth_wrong) {
    cout << "infinity";
    return;
  }

  cout << "single\n";
  for (auto i : ans)
    cout << i << ' ';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(16);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ll t = 1;
  // cin >> t;

  while (t--)
    solve();
}
