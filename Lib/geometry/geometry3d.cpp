#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

struct vec {
  ll x;
  ll y;
  ll z;
};

vec operator - (const vec a, const vec b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

void operator -= (vec& a, const vec b) {
  a = a - b;
}

ostream& operator << (ostream &os, const vec a) {
  return os << a.x << ' ' << a.y << ' ' << a.z;
}

istream& operator >> (istream &in, vec &a) {
  return in >> a.x >> a.y >> a.z;
}

ll sqlen(vec a) {
  return a.x * a.x + a.y * a.y + a.z * a.z;
}

ld len(vec a) { // |a|
  return sqrt(sqlen(a));
}

vec cross(vec a, vec b) { // [a, b]
  return {
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
  };
}

ll dot(vec a, vec b) { // (a, b)
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

ll mix(vec a, vec b, vec c) { // <a, b, c>
  return dot(cross(a, b), c);
}

ld angle(vec a, vec b) {
  return atan2(len(cross(a, b)), dot(a, b));
}

void solve() {
  vec a, b;
  cin >> a >> b;

  cout << angle(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
