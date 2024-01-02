#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const vector<pair<ll, ll>> knight = {
  {2, 1},
  {2, -1},
  {-2, 1},
  {-2, -1},
  {1, 2},
  {1, -2},
  {-1, 2},
  {-1, -2},
};

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
  return (b.p + b.d > g.p + g.d ||
          ((b.p + b.d == g.p + g.d) &&
           (b.p < g.p)));
}

ll h(ll ax, ll ay, ll bx, ll by) {
  ll b = abs(ax - bx);
  ll a = abs(ay - by);

  if (a > b)
    swap(a, b);

  if (a == 0 && b == 1)
    return 3;

  if (a == 2 && b == 2)
    return 4;

  if (2 * a <= b)
    return (b + 1) / 2;

  return (a + b + 1) / 3;
}

void solve() {
  ll y, x;
  set<node> q;
  map<pair<ll, ll>, ll> g;
  map<pair<ll, ll>, pair<ll, ll>> parent;

  cin >> x >> y;

  g[{0, 0}] = 0;
  q.emplace(0, 0, 0, h(0, 0, x, y));

  int counter = 0;

  while (!q.empty()) {
    auto [ux, uy, up, ud] = *q.begin();
    up++;
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
        g[{ux, uy}] = up;
        parent[{ux, uy}] = {ux - dx, uy - dy};
        q.emplace(ux, uy, up, h(ux, uy, x, y));
      }

      ux -= dx;
      uy -= dy;
    }
  }

  vector<pair<ll, ll>> ans;

  ll nx = x, ny = y;

  while (nx || ny) {
    auto [px, py] = parent[{nx, ny}];
    ans.emplace_back(nx, ny);
    nx = px;
    ny = py;
  }

  reverse(ans.begin(), ans.end());

  for (auto [a, b] : ans) {
    cout << a << ' ' << b << '\n';
  }
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

  ll t = 1;
  // cin >> t;

  while (t--)
    solve();
}
