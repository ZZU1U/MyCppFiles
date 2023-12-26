#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

int diff(int val) {
  int m = 0;
  
  while (val) {
    if (val % 2) {
      m += val % 10;
    } else {
      m -= val % 10;
    }
    val /= 10;
  }

  return m;
}
 
void solve() {
  int n;
  cin >> n;

  vector<int> vals(n);

  for (auto& i : vals)
    cin >> i;

  sort(all(vals), std::greater<>());

  for (auto i : vals) {
    if (abs(diff(i)) < 2) {
      cout << i;
      return;
    }
  }
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
