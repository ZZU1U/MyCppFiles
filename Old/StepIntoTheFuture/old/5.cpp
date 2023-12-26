#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;
 
void solve() {
  int n;
  int counter = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    unsigned int t;
    cin >> t;

    auto b = bitset<32>(t).to_string();

    bool fl = true;

    for (int j = 0; j < 32; j += 4) {
      if (b[j] == b[j + 1] && b[j + 2] == b[j + 3] && b[j] == b[j + 3] && b[j] == '0' && fl) {
        continue;
      }
      fl = false;
      counter += b[j + 2] == b[j + 3] && b[j + 2] == '0';
    }

  }

  cout << counter;
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
