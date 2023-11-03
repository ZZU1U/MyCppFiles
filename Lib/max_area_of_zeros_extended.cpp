#include <bits/stdc++.h>

using namespace std;

void l_r_min(vector<int>& v, int n, vector<int>& la, vector<int>& ra) {
  vector<int> stack_l;
  vector<int> stack_r;

  for (int i = 0; i < n; i++) {
    // LA
    while (!stack_l.empty() && v[i] <= v[stack_l.back()]) {
      stack_l.pop_back();
    }
    if (stack_l.empty()) {
      la[i] = -1;
    } else {
      la[i] = stack_l.back();
    }
    stack_l.push_back(i);

    // RA
    while (!stack_r.empty() && v[stack_r.back()] > v[i]) {
      ra[stack_r.back()] = i;
      stack_r.pop_back();
    }
    stack_r.push_back(i);
  }
  while (!stack_r.empty()) {
    ra[stack_r.back()] = n;
    stack_r.pop_back();
  }
}

int gistogram_area(int n, vector<int>& v) {
  vector<int> la(n), ra(n);

  l_r_min(v, n, la, ra);

  int best_s = -1;

  for (int i = 0; i < n; i++) {
    if ((ra[i] - la[i] - 1) * v[i] > best_s) {
      best_s = (ra[i] - la[i] - 1) * v[i];
    }
  }

  return best_s;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  bool t;
  int max_area = -1;

  cin >> n >> m;

  vector<int> heights(m);

  for (int i = 0; i < n; i++) {
    vector<int> diff(m);
    bool do_check = false;
    for (int j = 0; j < m; j++) {
      cin >> t;
      if (t) {
        diff[j] = 1;
        do_check = true;
      }
    }

    if (do_check) {
      max_area = max(max_area, gistogram_area(m, heights));
    }

    for (int j = 0; j < m; j++) {
      if (diff[j]) {
        heights[j] = 0;
      } else {
        heights[j]++;
      }
    }
  }
  cout << max(max_area, gistogram_area(m, heights));
}