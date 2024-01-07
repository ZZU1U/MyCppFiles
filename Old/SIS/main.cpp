#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const vector<pair<ll, ll>> knight = {
  {1, 0},
  {1, -1},
  {0, -1},
  {-1, 0},
  {-1, 1},
  {0, 1}
};

map<pair<ll, ll>, ll> p;

struct node {
  ll x, y, p, d; // cords, passed, dist

  node(ll x, ll y, ll p, ll d)
    : x(x)
    , y(y)
    , p(p)
    , d(d)
  {}
};

bool operator < (node g, node b) {
  return (b.p + b.d > g.p + g.d);
}

ll h(ll ax, ll ay, ll bx, ll by) {
  return max(abs(ax - ay), abs(bx - by)) / 2;
}

void solve() {
  ll y, x;
  set<node> q;
  map<pair<ll, ll>, ll> g;

  cin >> x >> y;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    p[{a, b}] = c;
  }

  g[{0, 0}] = 0;
  q.emplace(0, 0, 0, h(0, 0, x, y));

  int counter = 0;

  while (!q.empty()) {
    auto [ux, uy, up, ud] = *q.begin();
    counter++;
    q.erase(q.begin());

    if (ux == x && uy == y)
      break;

    for (auto [dx, dy] : knight) {
      ux += dx;
      uy += dy;
      // now ux and uy are vx and vy

      auto gv = g.find({ux, uy});

      if (gv == g.end() || up < gv->second) {
        auto pi = p.find({ux, uy});

        int pv = 1;

        if (pi != p.end()) {
          pv = pi -> second;
        }

        g[{ux, uy}] = up + pv;
        q.emplace(ux, uy, up + pv, h(ux, uy, x, y));

        cout << ux << ' ' << uy << '-' << ux - dx << ' ' << ux - dy << '\n';
      }

      ux -= dx;
      uy -= dy;
    }
  }

  cout << g[{x, y}] << ' ' << counter;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

  ll t = 1;
  // cin >> t;

  while (t--)
    solve();
}
