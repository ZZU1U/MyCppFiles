#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ukazateli G

// Problem - 25 is not counted

int get_index(vector<int> &vec, int n, int val) {
  for (int i = 0; i < n; i++) {
    if (vec[i] == val) {
      return i;
    }
  }

  vec.push_back(val);
  return n;
}

bool are_all_not_null(vector<int> &vec) {
  for (auto i : vec) {
    if (!i) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, t1, t2;

  vector<int> prd;

  cin >> n;

  vector<pair<int, int>> cows(n);

  for (int i = 0; i < n; i++) {
    cin >> t1 >> t2;
    t2 = get_index(prd, prd.size(), t2);

    cows[i] = make_pair(t1, t2);
  }

  sort(cows.begin(), cows.end());

  prd = vector<int> (prd.size(), 0);

  int j = 0, bd = -1;

  for (int i = 0; i < n; i++) {
    if (i) {
      prd[cows[i-1].second]--;
    }
    while (!are_all_not_null(prd) && j < n) {
      j++;
      prd[cows[j-1].second]++;
    }
    if (j == n) {
      break;
    }
    if ((bd == -1) || (bd > (cows[j].first - cows[i].first))) {
      bd = cows[j].first - cows[i].first;
      cout << cows[j].first << ' ' << cows[i].first << '\n';
    }
  }

  cout << bd;
}

