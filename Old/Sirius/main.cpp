#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

void solve() {
  vector<ll> n(3);
  for (auto& i : n)
    cin >> i;
  sort(n.begin(), n.end());

  if (n[1] - n[0] == n[2] - n[1]) {
    cout << 'A';
  } else if (n[1] * n[1] == n[0] * n[2]) {
    cout << 'G';
  } else {
    cout << "No";
    return;
  }

  for (auto i : n)
    cout << ' ' << i;

}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifdef DEBUG
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  solve();
}
