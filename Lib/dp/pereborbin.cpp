#include <bits/stdc++.h>

/*
 * This is default example for recursive iterating through all
 * possible variants (in russian it's called "perebor" - перебор)
 *
 * We have our func called gen, that add element, call itself
 * and then change last element to next possible one
 *
 * In this example we iterate through all possible binary codes with length n
 */

using namespace std;

typedef  long long ll;
#define all(x) x.begin(), x.end()

void gen(int i, int n, vector<int>& ans) {
  if (i == n) {
    for (auto k : ans) {
      cout << k;
    }
    cout << '\n';
    return;
  }
  for (int j = 0; j < 2; j++) {
    ans.push_back(j);
    gen(i+1, n, ans);
    ans.pop_back();
  }
}

void solve() {
  int n;
  cin >> n;

  vector<int> ans;
  gen(0, n, ans);
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  #endif

  int t = 1;

  while (t--) {
    solve();
    cout << '\n';
  }
}
