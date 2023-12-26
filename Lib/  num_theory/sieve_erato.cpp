#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<bool> erato(n+1, true);
  erato[1] = false;

  for (int i = 2; i < n; i++) {
    if (erato[i]) {
      for (int j = i * 2; j <= n; j+= i)
        erato[j] = false;
      cout << i << ' ';
    }
  }
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
