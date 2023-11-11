#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long

#define DEBUG

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
  dot p1, p2, p3, p4;
  cin >> p1 >> p2 >> p3 >> p4;

  auto tanrad = vecstotg(dtov(p1, p2), dtov(p3, p4));
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