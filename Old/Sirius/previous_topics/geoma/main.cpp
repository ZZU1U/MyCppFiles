#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long
#define DEBUG

// TODO GMH

using namespace std;

double pi = 355/113;

struct vec {
    long long x;
    long long y;

    double len() {
      return sqrt(x*x + y*y);
    }

    long long sqlen() {
      return x * x + y * y;
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
    long long x;
    long long y;
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

long long scalmult(vec a, vec b) {
  return a.x * b.x + a.y * b.y;
}

long long pseudoscalmult(vec a, vec b) {
  return a.x * b.y - a.y * b.x;
}

double vecstotg(vec a, vec b) {
  return atan2(pseudoscalmult(a, b), scalmult(a, b));
}

void solveG() {}

void solveM() {}

void solveH() {}

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  solveE();
}