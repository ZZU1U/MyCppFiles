#include <iostream>
#include <vector>

using namespace std;

// We find nearest number to given in list of numbers
// It seems easy to code, but i had some troubles, so I'm better to save this

int binary_search_ans_in_l(vector<int> &v, int target) {
  int l = 0;
  int r = (int) v.size();
  int m;

  while (r - l > 1) {
    m = (r + l) / 2;
    if (target >= v[m]) {
      l = m;
    } else {
      r = m;
    }
  }

  return v[l];
}

int binary_search_ans_in_r(vector<int> &v, int target) {
  int l = -1;
  int r = (int) v.size() - 1;
  int m;

  while (r - l > 1) {
    m = (r + l) / 2;
    if (target > v[m]) {
      l = m;
    } else {
      r = m;
    }
  }

  return v[r];
}

int main() {
  int n, k, a, b;

  cin >> n >> k;

  vector<int> v(n);

  for (int i = 0; i < n; cin >> v[i++]) { }

  for (int i = 0; i < k; i++) {
    cin >> n;

    a = binary_search_ans_in_l(v, n);
    b = binary_search_ans_in_r(v, n);

    if (abs(n - a) <= abs(n - b)) {
      cout << a;
    } else {
      cout << b;
    }
    cout << '\n';
  }
}
