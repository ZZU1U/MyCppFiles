#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int INF = 1;
int n;

void floyd(vector<vector<int>>& dp) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (max(dp[i][k], dp[k][j]) != INF && dp[i][j] > dp[i][k] + dp[k][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
        }
      }
    }
  }
}

void solve() {
  cin >> n;

  vector<vector<int>> dp(n, vector<int>(n, INF));
  vector<vector<int>> dq(n, vector<int>(n, INF));

  vector<int> p(n);
  vector<int> q(n);

  for (auto& i : p) {
    cin >> i;
    i--;
  }

  for (auto& i : q) {
    cin >> i;
    i--;
  }

  for (auto i : p) {
    dp[i][p[i]] = 0;
    dp[i][i] = 0;
  }

  for (auto i : q) {
    dq[i][q[i]] = 0;
    dq[i][i] = 0;
  }

  floyd(dp);
  floyd(dq);

  int counter = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      counter += !(dp[i][j] | dq[i][j]);
    }
  }

  cout << (counter - n) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  #endif // DEBUG
  
  cout << fixed << setprecision(20);

  int t = 1;

  //cin >> t;
  
  while (t--) {
    solve();
    cout << '\n';
  }

  return 0;
}

