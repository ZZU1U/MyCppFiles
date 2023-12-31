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

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> step(n);

  for (int i = 0; i < 2 * m; i++) {
    int x;
    cin >> x;
    x--;
    step[x]++;
  }

  for (auto i : step)
    cout << i << ' ';
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
