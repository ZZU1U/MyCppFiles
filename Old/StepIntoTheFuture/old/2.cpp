#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

// Todo start from second

const int INF = 1000; // XD

int ci(char c) {
  return c - '0';
}
 
void solve() {
  char q, w, e, r, t, u;

  cin >> q >> w >> e >> r >> t >> u;

  int a = ci(q), b = ci(w), c = ci(e);
  int x = ci(r), y = ci(t), z = ci(u);

  int frcase = INF;
  int sdcase = INF;

  // First case
  int fsum = a + b + c;
  int ssum = y * 10 + z;
  
  int fd = ssum - fsum / 10 - fsum % 10;

  if (fd % 2 == c % 2 && fd) {
    frcase = fd * 100 + fsum;
  }

  // Second case
  fsum = x + y + z;
  ssum = b * 10 + c;

  fd = ssum - fsum / 10 - fsum % 10;

  if (fd % 2 == z % 2 && fd) {
    sdcase = fd * 100 + fsum;
  }

  int ans = min(frcase, sdcase);

  // Center case
  int asum = b * 10 + c;
  int bsum = y * 10 + z;

  int nans = INF;

  if (asum == bsum) {
    asum--;
    if (c % 2 != x % 2 || a % 2 != z % 2) {
      nans = 100 + (asum % 2 ? asum : asum + 1);
    } else if (c % 2 == 0) {
      asum--;
      nans = 200 + (asum % 2 == 0 ? asum : asum + 9);
    } else {
      nans = 100 + (asum % 2 ? asum : asum + 9);
    }
  }

  ans = min(ans, nans);

  // Answer

  cout << (ans != INF ? max(min(ans, min(a * 100 + b * 10 + c, x * 100 + y * 10 + z)), -1) : -1);
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
