#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * The task is to find maximum area of solid rectangle of zeros
 *
 * Example input:
 * 5 6
 * 1 0 0 0 1 0
 * 0 0 0 0 1 0
 * 0 0 1 0 0 0
 * 0 0 0 0 0 0
 * 0 0 1 0 0 0
 *
 * Example output:
 * 9
 *
 * In this problem we will iterate through our rows and choose the lowest one
 * When we chose our lowest row, we can solve this as another problem - maximum area of rectangle under gistogram
 * gistogram - in russian, bar chart - in english
 *
 * If you need some comments you can check gistogram_max_s.cpp (min_rights, min_lefts and gistogram_area source)
 */

vector<int> min_rights(vector<int>& vec, int n) {
    vector<int> ans(n);
    vector<int> stack;

    for (int i = n-1; i >= 0; i--) {
        while (!stack.empty() && vec[stack.back()] >= vec[i]) {
          stack.pop_back();
        }

        if (stack.empty()) {
            ans[i] = n;
        } else {
            ans[i] = stack.back();
        }

        stack.push_back(i);
    }

    return ans;
}

vector<int> min_lefts(vector<int>& vec, int n) {
    vector<int> ans(n);
    vector<int> stack;

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && vec[stack.back()] >= vec[i]) {
            stack.pop_back();
        }

        if (stack.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = stack.back();
        }

        stack.push_back(i);
    }

    return ans;
}

int gistogram_area(int n, vector<int>& v) {
  vector<int> ans_rights = min_rights(v, n);

  vector<int> ans_lefts = min_lefts(v, n);

  int bi = -1;

  for (int i = 0; i < n; i++) {
    if (bi == -1 || (ans_rights[i] - ans_lefts[i] - 1) * v[i] > v[bi] * (ans_rights[bi] - ans_lefts[bi] - 1)) {
      bi = i;
    }
  }

  return v[bi] * (ans_rights[bi] - ans_lefts[bi] - 1);
}

int main() {
    // Start of very important code for good time
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // End

    int n, m;
    bool t;
    int max_area = -1;

    cin >> n >> m;

    vector<int> heights(m);

    for (int i = 0; i < n; i++) {
      /*
       * So there we cin each row
       * And count height of each row of zeros
       */
      for (int j = 0; j < m; j++) {
        cin >> t;
        if (t) {
          heights[j] = 0;
        } else {
          heights[j]++;
        }
      }
      max_area = max(max_area, gistogram_area(m, heights));
    }
    cout << max_area;
}
