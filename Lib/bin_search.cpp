#include <iostream>
#include <vector>

/*
 * This is a simple realization of binary search in c++
 */

using namespace std;

unsigned int binary_search_ans_in_l(vector<int> &v, int target) { // so long name
  unsigned int l = 0;
  unsigned int r = v.size();
  unsigned int m;

  while (r - l > 1) {
    m = (r + l) / 2;
    if (target >= v[m]) { // If we want ans in r we just change to >
      l = m;
    } else {
      r = m;
    }
  }

  return l;
}

int main() {
  int n, m;

  cin >> n >> m;

  vector<int> v(n);

  for(int i = 0; i < n; cin >> v[i++]) { }

  cout << binary_search_ans_in_l(v, m);
}
