#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()

void solve() {
  unsigned long long a = 1;

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    a = a * i;
  }

  cout << a;
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  #endif

  solve();
}
