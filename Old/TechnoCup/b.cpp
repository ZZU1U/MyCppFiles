#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

void solve() {
  ll n;
  cin >> n;

  ll rn = ~n;
  
  cout << n << '\n' << bitset<6>(n) << '-' << bitset<6>(rn) << '\n';

  ll val = sqrt(n);

  ll counter = 0;

  while (val > 0) {
    if (!(n & val)) {
      counter += 1 + (val * val != n);
      break;
    }
    val--;
  }

  if (!val) {
    cout << counter;
    return;
  }

  int a=0, b=0;

  while(val > 0) {
    if (val & 1 && rn & 1) {
      a += pow(2, b);
    } else {
      b++;
    }
    val >>= 1;
    rn >>= 1;
    cout << bitset<6>(val) << '\n';
  }

  cout << counter << ' ' << a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  #endif // DEBUG
  
  cout << fixed << setprecision(20);

  int t = 1;

  cin >> t;
  
  while (t--) {
    solve();
    cout << '\n';
  }

  return 0;
}

