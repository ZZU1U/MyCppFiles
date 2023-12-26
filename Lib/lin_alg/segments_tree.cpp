#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct unit {
  int val;
};

unit operator+(unit a, unit b) {
  return {a.val + b.val};
}

istream& operator >> (istream& in, unit& a) {
  return in >> a.val;
}

ostream& operator << (ostream& os, unit a) {
  return os << a.val;
}


vector<unit> tree;


void build(int v, int l, int r, const vector<unit>& vec) {
  if (r - l == 1) {
    tree[v] = vec[l];
    return;
  }

  int m = (l + r) / 2;

  build(v * 2 + 1, l, m, vec);
  build(v * 2 + 2, m, r, vec);

  tree[v] = tree[v*2 + 1] + tree[v*2 + 2];
}


unit get(int v, int l, int r, const int& x, const int& y) {
    if (l >= x && r <= y)
        return tree[v];

  if (l >= y || r <= x)
    return {0};

  int m = (l + r) / 2;

  return get(2 * v + 1, l, m, x, y) + get(2 * v + 2, m, r, x, y);
}


void change(int v, int l, int r, const int& ind, const unit& val) {
  if (r - l == 1) {
    tree[v] = val;
    return;
  }

  int m = (l + r) / 2;

  if (ind <= m)
    change(v*2 + 1, l, m, ind, val);
  else
    change(v*2 + 2, m, r, ind, val);

  tree[v] = tree[v*2 + 1] + tree[v*2 + 2];
}


void solve() {
  int n;
  cin >> n;
  vector<unit> v(n);
  tree.resize(4*n);

  for (auto& i : v) cin >> i;

  build(0, 0, n, v);

    for (auto i : tree) {
        cout << i << ' ';
    }

  int q;
  cin >> q;

  cout << '\n';

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    cout << get(0, 0, n, l, r) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
//  cout.tie(nullptr);
//  cin.tie(nullptr);

  int t = 1;
//  cin >> 1;

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freope("output.txt", "w", stdout);
#endif

  while (t--) solve();

}
