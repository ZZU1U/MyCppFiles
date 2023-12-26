#include <bits/stdc++.h>

using namespace std;

bool is_pow_of_two(int n) {
  return !(n & (n-1));
}

void solve() {
  int n;
  cin >> n;

  cout << is_pow_of_two(n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}

