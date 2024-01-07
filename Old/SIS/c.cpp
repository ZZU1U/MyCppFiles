#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;

using namespace std;

random_device rd;
mt19937 rng(rd());

const int BIGNUM = 21000000;

vector<vector<int>> m;

int target;

int n, k;

int metric(int a, int b) {
  return abs(m[a][n] - target) + abs(m[b][n] - target);
}

void solve() {
  cin >> n >> k;

  target = n * (n + 1) / 2 / k;

  n = n / k;

  m.resize(k, vector<int>(n + 1));

  m[0][0] = 1;

  for (int i = 0; i < k; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (!m[i][j]) {
        if (j) {
          m[i][j] = m[i][j-1] + 1;
        } else {
          m[i][j] = m[i - 1][n - 1] + 1;
        }
      }
      sum += m[i][j];
    }
    m[i][n] = sum;
  }

  int counter = 0;

  for (int i = 0; i < BIGNUM && counter < BIGNUM; i++) {
    int sa = rng() % k;
    int sb = rng() % k;
    int sc = rng() % n;
    int sd = rng() % n;

    if ((m[sa][n] > m[sb][n]) != (m[sa][sc] > m[sb][sd]) || m[sa][n] == target || m[sb][n] == target) {
      continue;
    }

    m[sa][n] -= m[sa][sc];
    m[sa][n] += m[sb][sd];

    m[sb][n] -= m[sb][sd];
    m[sb][n] += m[sa][sc];
    swap(m[sa][sc], m[sb][sd]);
  }

  for (int i = 0; i < k; i++) {
    if (target != m[i][n]) {
      cout << 0;
      return;
    }
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cout << m[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(24);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
