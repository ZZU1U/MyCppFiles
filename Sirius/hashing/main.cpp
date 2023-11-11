#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long
#define DEBUG

using namespace std;

const ll p = 60;
const ll q = 1000000007;

struct Hash {
    ll value;
};

ostream& operator << (ostream &os, const Hash& a) {
  return os << a.value % q;
}

Hash operator+(const Hash& a, const Hash& b) {
  ll res = (a.value + b.value) % q;
  return {res};
}

Hash operator+(const Hash& a, const ll& b) {
  ll res = (a.value + b) % q;
  return {res};
}

Hash operator-(const Hash& a, const Hash& b) {
  ll res = (a.value - b.value) % q; if (res < 0) {
    res += q;
  }
  return {res};
}

Hash operator-(const Hash& a, const ll& b) {
  ll res = (a.value - b) % q;
  return {res};
}

Hash operator*(const Hash& a, const Hash& b) {
  return {a.value * b.value % q};
}

Hash operator*(const Hash& a, const ll& b) {
  return {a.value * b % q};
}

bool operator==(const Hash& a, const Hash& b) {
  return a.value == b.value;
}

Hash ctoh(char chr) {
  return Hash{chr - 'a' + 1};
}

ll hache(int l, int r, vector<Hash>& hashe, vector<ll> ps) {
  return (hashe[r] - hashe[l] * ps[r - l]).value;
}

void solveI() {
  string glob;
  getline(cin, glob);
  int n = glob.size();

  vector<ll> ps = {1};
  for (int i = 0; i < n; i++) {
    ps.push_back(ps.back() * p % q);
  }
  vector<Hash> hach = {{0}};
  for (int i = 0; i < n; i++) {
    hach.push_back(hach[i] * p + ctoh(glob.at(i)));
  }

  reverse(all(glob));

  vector<Hash> rhach = {{0}};
  for (int i = 0; i < n; i++) {
    rhach.push_back(rhach[i] * p + ctoh(glob.at(i)));
  }
  for (int i = 0; i < n; i++) {
    // i - center
    int l = 0;
    int r = min(i, n - i - 1) + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (hache(i-m, i, hach, ps) == hache(n-i-m-1, n-i-1, rhach, ps)) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << 1 + l * 2 << ' ';
  }
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  solveI();
}
