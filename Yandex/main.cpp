#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> sq(n, vector<bool>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      sq[i][j] = t;
    }
  }

}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
