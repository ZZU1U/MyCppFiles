#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;

using namespace std;

bool pot(int a) { // Power Of Two (ne banyte pozhalusta, normalnoe nazvanie)
  return !(a & (a - 1));
}

string encode(const string& x) {
  int n = x.length();

  string y;
  int ctrl = 0;

  for (int i = 1; i <= n + ctrl; i++) {
    if (pot(i)) {
      ctrl++;
      y.push_back('3');
    } else
      y.push_back(x[i - 1 - ctrl]);
  }

  n = y.length();

  for (int i = 1; i <= n; i++) {
    if (y[i-1] == '3') {
      int counter = 0;
      for (int j = i; j <= n; j+=i*2) {
         for (int k = 0; k < i && j + k <= n; k++) {
           counter += (y[j + k - 1] - '0');
         }
      }
      y[i-1] = '0' + counter % 3;
    }
  }

  return y;
}

pair<string, string> divide(const string& y) {
  int n = y.length();
  string control, data;

  for (int i = 0; i < n; i++) {
    if (pot(i + 1)) {
      control.push_back(y[i]);
    } else {
      data.push_back(y[i]);
    }
  }

  return {control, data};
}

void reverse(string& str, const int index, int rpl) {
  str[index] = '0' + rpl % 3;
}

string decode(string& y) {
  auto [control, data] = divide(y);

  int replacement = 0;

  string new_control = divide(encode(data)).first;

  int counter = 0;

  for (int i = 0; i < control.length(); i++) {
    if (new_control[i] != control[i]) {
      counter += (1 << i);
      replacement += new_control[i] - control[i];
    }
  }


//  cout << counter << ' ' << replacement << '\n';

  if (counter)
    reverse(y, counter - 1, abs(replacement));

//  cout << y << '\n';

  return divide(y).second;
}

void solve() {
  int type;
  string str;
  cin >> type >> str;

  switch (type) {
  case 1: {
    cout << encode(str);
    break;
  }
  case 2: {
    cout << decode(str);
    break;
  }
  default: return;
  }

  cout.flush();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(24);

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
