#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;

using namespace std;

void solve() {
  ll k;
  cin >> k;

  if (k & 1) {
    cout << -1;
    return;
  }

  auto b = bitset<65>(k).to_string();

  reverse(b.begin(), b.end());

  vector<int> ans;
  int counter = 0;

  for (int i = 0; i < 65; i++) {
    if (b[i] == '1') {
      ans.push_back(i - 1);
      counter += i;
    }
  }

  cout << counter << '\n';

  for (auto i : ans) {
    for (int j = 0; j < i; j++) {
      cout << "0 ";
    }
    cout << "1 ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(24);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
