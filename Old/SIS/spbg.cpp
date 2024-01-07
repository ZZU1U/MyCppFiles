#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;

using namespace std;

const int mod = 1e9 + 7;
const int p = 29;

struct Hash {
    int value;
    Hash(int val = 0) : value(val) {}
};

Hash operator+(const Hash& a, const Hash& b) {
    int res = a.value + b.value;
    return {res < mod ? res : res - mod};
}

Hash operator-(const Hash& a, const Hash& b) {
    int res = a.value - b.value;
    return {res >= 0 ? res : res + mod};
}

Hash operator*(const Hash& a, const Hash& b) {
    return {int((long long)a.value * b.value % mod)};
}

bool operator==(const Hash& a, const Hash& b) {
    return a.value == b.value;
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
