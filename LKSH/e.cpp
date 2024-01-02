#include <bits/stdc++.h>

typedef int ll;
typedef long double ld;

using namespace std;

ll MOD = 1e9 + 7;

struct matrix {
  ll n, m;
  vector<vector<ll>> M;

  vector<ll>& operator [](ll i) {
    return this->M[i];
  }

  void operator %= (const ll mod) {
    for (auto& i : M)
      for (auto& j : i)
        j %= mod;
  }

  void operator *= (matrix b) {
    vector<vector<ll>> K(n, vector<ll>(b.m));

    for (ll k = 0; k < m; k++)
      for (ll i = 0; i < n; i++)
        for (ll j = 0; j < b.m; j++)
          K[i][j] += M[i][k] * b[k][j] % MOD;

    M = K;
  }
};

istream& operator >> (istream& in, matrix& a) {
  a.M.resize(a.n, vector<ll>(a.m));

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

matrix null_matrix(const ll n) {
  vector<vector<ll>> m(n, vector<ll>(n));

  for (ll i = 0; i < n; i++)
    m[i][i] = 1;

  return {n, n, m};
}

matrix operator - (matrix a, matrix b) {
  for (ll i = 0; i < a.n; i++)
    for (ll j = 0; j < a.m; j++)
      a[i][j] -= b[i][j];

  return a;
}

matrix operator + (matrix a, matrix b) {
  for (ll i = 0; i < a.n; i++)
    for (ll j = 0; j < a.m; j++)
      a[i][j] += b[i][j];

  return a;
}

matrix operator * (matrix a, matrix b) { // a.m == b.n
  vector<vector<ll>> K(a.n, vector<ll>(b.m));

  for (ll k = 0; k < a.m; k++)
    for (ll i = 0; i < a.n; i++)
      for (ll j = 0; j < b.m; j++)
        K[i][j] += a[i][k] * b[k][j];

  return {a.n, b.m, K};
}

void inplace_pow(matrix& a, long long pow) {
  matrix temp = null_matrix(a.n);

  while (pow) {
    if (pow & 1) {
      temp *= a;
      temp %= MOD;
    }

    a *= a;
    a %= MOD;
    pow >>= 1;
  }

  a = temp;
}

void solve() {
  // fi[i] = a · f[i−1] + b · f[i−2] + c · 2^i + d · i + e, для i > 2

  ll a, b, c, d, e;
  long long n;

  cin >> a >> b >> c >> d >> e >> n;

  matrix F = {
    5, 5,
    {
      {a, b, c, d, e},
      {1, 0, 0, 0, 0},
      {0, 0, 2, 0, 0},
      {0, 0, 0, 1, 1},
      {0, 0, 0, 0, 1}
    }
  };

  matrix start = {
    5, 1,
    {
      {1}, // f[i-1]
      {1}, // f[i-2]
      {8}, // 2^(i)
      {3}, // i
      {1}  // 1
    }
  };

  // cout << F << '\n' << start;

  if (n < 3) {
    cout << 1;
    return;
  }

  inplace_pow(F, n - 2);

  F *= start;

  cout << F[0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ll t = 1;
  // cin >> t;

  while (t--)
    solve();
}
