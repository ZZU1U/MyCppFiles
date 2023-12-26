#include <bits/stdc++.h>

/*
 * This is a template for solving gemotry problems in c++
 * Such as finding an angle between vectors (geometry vectors)
 */

using namespace std;

struct vec {
    double x;
    double y;

    double len() {
      return sqrt(x*x + y*y);
    }
};

vec operator + (vec a, vec b) {
  return vec{a.x + b.x, a.y + b.y};
}

ostream& operator << (ostream &os, const vec a) {
  return os << a.x << " " << a.y;
}

istream& operator >> (istream &in, vec &a) {
  return in >> a.x >> a.y;
}

struct dot {
    double x;
    double y;
};

ostream& operator << (ostream &os, const dot a) {
  return os << a.x << " " << a.y;
}

istream& operator >> (istream &in, dot &a) {
  return in >> a.x >> a.y;
}

vec dtov(dot a, dot b) { // a is start, b is end
  return vec{b.x - a. x, b.y - a.y};
}

double scalmult(vec a, vec b) {
  return a.x * b.x + a.y * b.y;
}

double pseudoscalmult(vec a, vec b) {
  return a.x * b.y - a.y * b.x;
}

double vecstotg(vec a, vec b) {
  return atan2(pseudoscalmult(a, b), scalmult(a, b));
}

void solve() {
  dot a, b;
  cin >> a >> b;
  auto v1 = dtov(a, b);

  cin >> a >> b;
  auto v2 = dtov(a, b);

  cout << v1.len() << ' ' << v2.len() << '\n';

  cout << v1 + v2 << '\n';

  cout << scalmult(v1, v2) << ' ' << pseudoscalmult(v1, v2) << '\n';

  cout << abs(pseudoscalmult(v1, v2) / 2);
}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  solve();
}
