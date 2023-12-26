#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// Finding the minimal divisor for each number

void solve() {
  int n;
  cin >> n;

  vector<int> p(n + 1);
  vector<int> ans;

  for (int i = 2; i <= n; i++) {
    if (!p[i]) {
      cout << i << " is simple\n";
      p[i] = i;
      ans.push_back(i);
    }
    // Iterate through every simple number
    // And try to make better answer for number j * i, it will be min(p[i] and j)
    for (int j = 0; j < ans.size() && ans[j] * i <= n; j++) {
      p[ans[j] * i] = min(p[i], (p[j*i] ? min(ans[j], p[j * i]) : ans[j]));
    }
  }
  
  for (int i = 0; i < n; cout << i++ << ' ') { }
  cout << '\n';
  for (auto i : p)
    cout << i << ' ';
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
